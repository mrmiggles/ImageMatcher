#include "stdafx.h"
#include "Detector.h"

Ptr<FeatureDetector> Detector::getDetector(int type)
{
	//Brisk Parameters
	int Threshl = 45;
	int Octaves = 4;
	float PatternScales = 1.0f;

	switch (type) {
	case 1:
		cout << "AKAZE detector set" << endl;
		return AKAZE::create();
		break;
	case 2:
		cout << "ORB detector set" << endl;
		return  ORB::create(10000);
		break;
	case 3: //"SURF";
		cout << "SURF detector set" << endl;
		return SurfFeatureDetector::create(400); //minHessian = 400
		break;
	case 4:
		cout << "BRISK detector set" << endl;
		return BRISK::create(Threshl, Octaves, PatternScales);
		break;
	default:
		cout << "SIFT detector set" << endl;
		return SiftFeatureDetector::create();
		break;
	}

	
}
