#include <vector>
#include <string>

#include "../common/assert.hpp"
#include "../io/inputImage.hpp"
#include "../recorder/recorder.hpp"
#include "../common/assert.hpp"

#ifndef OPTONAUT_MINIMAL_IMAGE_PREPERATION_HEADER
#define OPTONAUT_MINIMAL_IMAGE_PREPERATION_HEADER

namespace optonaut {
namespace minimal {

    bool CompareByFilename (const std::string &a, const std::string &b) {
        return IdFromFileName(a) < IdFromFileName(b);
    }

    class ImagePreperation {
        public:

        static std::vector<InputImageP> CreateMinifiedCopy(
                const std::vector<InputImageP> &in, int downsample = 2) {

            std::vector<InputImageP> copies; 

            AssertGT(downsample, 0);

            for(auto img : in) {
                InputImageP copy(new InputImage());
                bool loaded = false;

                if(!img->image.IsLoaded()) {
                    loaded = true;
                    img->image.Load();
                }

                cv::Mat small;

                pyrDown(img->image.data, small);

                for(int i = 1; i < downsample; i++) {
                    pyrDown(small, small);
                }

                if(loaded) {
                    img->image.Unload();
                }

                copy->image = Image(small);
                copy->dataRef = img->dataRef;
                copy->originalExtrinsics = img->originalExtrinsics.clone();
                copy->adjustedExtrinsics = img->adjustedExtrinsics.clone();
                copy->intrinsics = img->intrinsics.clone();
                copy->exposureInfo = img->exposureInfo;
                copy->id = img->id;

                copies.push_back(copy);
            }
            
            return copies;
        }

        static void CopyExtrinsics(
                const std::vector<InputImageP> &from, std::vector<InputImageP> &to) {
            auto byId = CreateImageMap(from);

            for(auto img : to) {
                byId.at(img->id)->adjustedExtrinsics.copyTo(img->adjustedExtrinsics);
                byId.at(img->id)->originalExtrinsics.copyTo(img->originalExtrinsics);
            }
        }
       
        static std::vector<InputImageP> LoadAndPrepare(
                std::vector<std::string> files, 
                bool shallow = true, int limit = -1, int step = 1) {
            
            std::sort(files.begin(), files.end(), CompareByFilename);

            std::vector<InputImageP> allImages;

            auto base = optonaut::Recorder::iosBase;
            auto zero = Recorder::iosZero;
            auto baseInv = base.t();

            int n = files.size();
            limit = limit * step;

            if(limit > 0) {
                n = std::min(limit, n);
            }
            
            for(int i = 0; i < n; i += step) {
                auto img = InputImageFromFile(files[i], shallow); 
                img->originalExtrinsics = base * zero * 
                    img->originalExtrinsics.inv() * baseInv;
                img->adjustedExtrinsics = img->originalExtrinsics;

                allImages.push_back(img);
            }

            return allImages;
        } 

        static void LoadAllImages(std::vector<InputImageP> &images) {
            for(auto img : images) {
                if(!img->image.IsLoaded()) {
                    img->image.Load();
                }
            }
        }

        static std::vector<InputImageP> LoadAndPrepareArgs(
                const int argc, char** argv, bool shallow = true, 
                int limit = -1, int step = 1) {
            int n = argc - 1;

            std::vector<std::string> files;

            for(int i = 0; i < n; i++) {
                std::string imageName(argv[i + 1]);

                if(imageName == "-n") {
                    AssertGT(n, i + 1);
                    limit = ParseInt(std::string(argv[i + 2]));
                    i++;
                } else if (imageName == "-s") {
                    AssertGT(n, i + 1);
                    step = ParseInt(std::string(argv[i + 2]));
                    i++;
                } else {
                    files.push_back(imageName);
                }
            }

            return LoadAndPrepare(files, shallow, limit, step);
        }

        static std::map<size_t, InputImageP> CreateImageMap(
                const std::vector<InputImageP> &images) {
            
            std::map<size_t, InputImageP> imageById;

            for(auto img : images) {
                imageById[img->id] = img;
            }

            return imageById;
        }
    };
}
}
#endif