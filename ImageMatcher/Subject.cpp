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
	keypoints = kp;
}

void Subject::setDescriptorsFromFloatBuffer(float *descs, int rows, int cols, int matType)
{
	descriptors = cv::Mat(rows, cols, matType, descs);
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
	return descriptors;
}

vector<cv::KeyPoint> Subject::getKeypoints()
{
	return keypoints;
}

void Subject::printDescriptors() {
	cout << descriptors << endl;
}

void Subject::checkSubjectKeypoints() {
	cout << "Subject Keypoints: " << keypoints.size() << endl;
	cout << "Subject Descriptors: " << descriptors.size() << endl;
}

void Subject::cleanUp()
{
	keypoints.clear();
	descriptors.release();
	subjectImage.release();
}

Subject::Subject()
{
}


Subject::~Subject()
{
}
