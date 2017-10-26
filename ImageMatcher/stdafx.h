// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

//define 
#define DECLDIR __declspec(dllexport)
#define DLL_EXPORT


// Windows Header Files:
#include <windows.h>

// additional libraries
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//Opencv 3.3 specific
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>


//custom libraries
#include "FeatureExtractor.h"
#include "Detector.h"
#include "Matcher.h"
#include "MatchResult.h"
#include "Subject.h"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;


extern "C"
{

}
