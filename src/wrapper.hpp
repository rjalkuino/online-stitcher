
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "core.hpp"

#ifndef OPTONAUT_WRAPPER_HEADER
#define OPTONAUT_WRAPPER_HEADER

namespace optonaut {
namespace wrapper {
	void Debug();
	void Push(double extrinsics[], double intrinsics[], unsigned char *image, int width, int height, double newExtrinsics[], int id);
	Image* GetLastImage();
	void Free();
	Image* AllocateImage(double extrinsics[], double intrinsics[], unsigned char *image, int width, int height, int id);
}
}
#endif