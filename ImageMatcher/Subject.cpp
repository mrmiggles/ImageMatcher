#include "stdafx.h"
#include "Subject.h"


void Subject::setImage(Mat sI)
{
	subjectImage = sI.clone();
}

Mat Subject::getImage()
{
	return subjectImage;
}

void Subject::setKeypoints(vector<cv::KeyPoint> kp)
{
	keypointsA = kp;
}


void Subject::addToKeyPoints(float x, float y) {
	cv::KeyPoint kp;
	cv::Point2f p;
	p.x = x;
	p.y = y;
	kp.pt = p;
	//keypointsA.push_back(kp);
}


Mat Subject::getDescriptors()
{
	return descriptorsA;
}

vector<cv::KeyPoint> Subject::getKeypoints()
{
	return keypointsA;
}

void Subject::printDescriptors() {
	cout << descriptorsA << endl;
}

void Subject::checkSubjectKeypoints() {
	cout << "Subject Keypoints: " << keypointsA.size() << endl;
	cout << "Subject Descriptors: " << descriptorsA.size() << endl;
}

void Subject::cleanUp()
{
	keypointsA.clear();
	descriptorsA.release();
	subjectImage.release();
	clearDescAsChar();
}

Subject::Subject()
{
}


Subject::~Subject()
{
}
