
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>


#ifndef OPTONAUT_CORE_HEADER
#define OPTONAUT_CORE_HEADER

namespace optonaut {
	struct Image {
		cv::Mat img;
		cv::Mat extrinsics;
		cv::Mat intrinsics; 
		int id;
		std::string source;

		std::vector<cv::KeyPoint> features;
		cv::Mat descriptors;
	};

	Image* ImageFromFile(std::string path);
}

#endif