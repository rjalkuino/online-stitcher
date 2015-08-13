#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <memory>

#include "image.hpp"
#include "support.hpp"

namespace optonaut {
struct StitchingResult {
	cv::Mat image;
	cv::Mat mask;
	std::vector<cv::Point> corners;
	std::vector<cv::Size> sizes;
	//Most top-right corner.
	cv::Point corner;
};

typedef std::shared_ptr<StitchingResult> StitchingResultP;

//Fast pure R-Matrix based stitcher
class RStitcher {
	public:
		bool compensate = false;
		bool seam = false;
		float workScale = 0.2f;
		float warperScale = 800;

		StitchingResultP Stitch(std::vector<ImageP> images, bool debug = false);
		static std::vector<ImageP> PrepareMatrices(std::vector<ImageP> r);
};
}
