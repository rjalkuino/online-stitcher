#include <algorithm>
#include <string>
#include <opencv2/features2d.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/stitching/detail/matchers.hpp>

#include "../math/projection.hpp"

#ifndef OPTONAUT_DRAWING_DEBUG_HEADER
#define OPTONAUT_DRAWING_DEBUG_HEADER

using namespace cv;
using namespace cv::detail;
using namespace std;

namespace optonaut {

    static inline void DrawPoly(const Mat &target, const vector<Point2f> &corners, const Scalar color = Scalar(255, 0, 0)) {
        
        Point2f last = corners.back();

        for(auto point : corners) {
            line(target, last, point, color, 4);
            last = point;
        }
    }

    static inline void DrawBox(const Mat &target, const cv::Rect &roi, const Scalar color = Scalar(255, 0, 0)) {
        std::vector<Point2f> corners;
        corners.emplace_back(roi.x, roi.y);
        corners.emplace_back(roi.x, roi.y + roi.height);
        corners.emplace_back(roi.x + roi.width, roi.y + roi.height);
        corners.emplace_back(roi.x + roi.width, roi.y);

        DrawPoly(target, corners, color);
    }

    
    static inline void DrawBar(cv::Mat &image, double val) {
        Scalar color;
        if(val < 0) {
            color = Scalar(0, 255, 255);
        } else {
            color = Scalar(255, 0, 255);
        }
        cv::rectangle(image, cv::Point(0, image.rows * (0.5 - val)), cv::Point(image.cols, image.rows * 0.5), color, CV_FILLED);
    }
    
    static inline void DrawMatchingHomographyBorder(const Mat &homography, const Mat &left, const Scalar &color, Mat &target) {
        std::vector<Point2f> scene_corners = GetSceneCorners(left, homography);

        Point2f offset(left.cols, 0);

        for(size_t i = 0; i < scene_corners.size(); i++) {
            scene_corners[i] += offset;
        }

        DrawPoly(target, scene_corners, color);
    }

    static inline void DrawMatchingResults(const Mat &homography, const Mat &homographyFromRot, const Mat &a, const Mat &b, Mat &target) {
        
        a.copyTo(target(cv::Rect(0, 0, a.cols, a.rows)));
        b.copyTo(target(cv::Rect(a.cols, 0, b.cols, b.rows)));

        DrawMatchingHomographyBorder(homography, a, Scalar(0, 255, 0), target);
        DrawMatchingHomographyBorder(homographyFromRot, a, Scalar(255, 0, 0), target);
    }
}

#endif

