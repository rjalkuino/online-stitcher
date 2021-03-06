//
//  recorder.c
//  Optonaut
//
//  Created by Emi on 29/08/15.
//  Copyright © 2015 Optonaut. All rights reserved.
//

#include "recorder.hpp"

using namespace cv;
using namespace std;

namespace optonaut {
    //Portrait to landscape (use with ios app)
    double iosBaseData[16] = {
        1, 0, 0, 0,
        0, -1, 0, 0,	
        0, 0, -1, 0,
        0, 0, 0, 1
    };

    //Landscape L to R (use with android app)
    double androidBaseData[16] = {
        -1, 0, 0, 0,
        0, -1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    double iosZeroData[16] = {
        0, 1, 0, 0,
        0, 0, 1, 0,
        1, 0, 0, 0,
        0, 0, 0, 1
    };

    double androidZeroData[16] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

#ifndef __ANDROID__

    Mat Recorder::androidBase(4, 4, CV_64F, androidBaseData);
    Mat Recorder::iosBase(4, 4, CV_64F, iosBaseData);
    Mat Recorder::iosZero = Recorder::iosBase * Mat(4, 4, CV_64F, iosZeroData) * Recorder::iosBase.inv();
    Mat Recorder::androidZero = Recorder::androidBase * Mat(4, 4, CV_64F, androidZeroData) * Recorder::androidBase.inv();

#endif

    string Recorder::tempDirectory = "tmp/";
    string Recorder::version = "0.7.0";
    
}

