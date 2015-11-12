////////////////////////////////////////////////////////////////////////////////////////
//
// Beem mono stitcher test by Emi
//
// Let there be MSV!
//
//

#include "../common/image.hpp"
#include "../recorder/recorderController.hpp"
#include "../recorder/exposureCompensator.hpp"

#ifndef OPTONAUT_MONO_STITCH_HEADER
#define OPTONAUT_MONO_STITCH_HEADER

namespace optonaut {
    struct StereoTarget {
        cv::Mat center;
        cv::Mat corners[4];
    };

	struct StereoImage {
		InputImageP A;
		InputImageP B;
		cv::Mat extrinsics; //Center
		bool valid;

		StereoImage() : A(new InputImage()), B(new InputImage()), extrinsics(4, 4, CV_64F), valid(false) { }
	};

    class MonoStitcher {
        private: 
        public:
            MonoStitcher() { }
            void CreateStereo(const SelectionInfo &a, const SelectionInfo &b, StereoImage &stereo);
    };
}

#endif