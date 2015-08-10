#include "wrapper.hpp"
#include "testbed.cpp"

using namespace std;
using namespace optonaut;

int main(int argc, char* argv[]) {
    
    //Shitty IOS debug code. 
    double extrinsics[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    double intrinsics[9] = {5, 0, 4, 0, 5, 4, 0, 1};
    double outExtrinsics[16];
    int width = 640; 
    int height = 480;

    unsigned char image[640*480*4];
    int dataSize = 640*480*4;

    vector<Image*> images;

    wrapper::Debug();

    for(int i = 1; i < argc; i++) {

        string path(argv[i]);
        BufferFromBinFile(image, dataSize, path);

        path.replace(path.length() - 3, 3, "ext");
        BufferFromStringFile<double>(extrinsics, 16, path);

        path.replace(path.length() - 3, 3, "int");
        BufferFromStringFile<double>(intrinsics, 9, path);

        wrapper::Push(extrinsics, intrinsics, image, width, height, outExtrinsics, i);
        images.push_back(wrapper::GetLastImae());
        
        wrapper::GetLastImage()->extrinsics = cv::Mat(4, 4, CV_64F, outExtrinsics).clone();

        for(int i = 0; i < 16; i++) {
            cout << outExtrinsics[i] << " ";
        }
        cout << endl;
    }

    RStitcher stitcher;

    StitchingResult *res = stitcher.Stitch(images);
    imwrite("dbg/ios-res.jpg", res->image);
}


int IosMain(int argc, char* argv[]) {
     //Humble IOS debug code. 
    double extrinsics[16];
    double intrinsics[9];
    double outExtrinsics[16];
    int width = 640; 
    int height = 480;

    unsigned char image[640*480*4];
    int dataSize = 640*480*4;

    vector<optonaut::Image*> imgs;

    for(int i = 1; i < argc; i++) {
        string path(argv[i]);
        BufferFromBinFile(image, dataSize, path);
        cout << "Read " << dataSize << " bytes of image" << endl;

        path.replace(path.length() - 3, 3, "ext");
        BufferFromStringFile(extrinsics, 16, path);

        path.replace(path.length() - 3, 3, "int");
        BufferFromStringFile(intrinsics, 9, path);

        Image *img = wrapper::AllocateImage(extrinsics, intrinsics, image, width, height, i);
        imgs.push_back(img);
    }

    sort(imgs.begin(), imgs.end(), CompareById);

    StreamAlign(imgs);

    for(int i = 0; i < imgs.size(); i++) {
        delete imgs[i];
    }

    return 0;

}