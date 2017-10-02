#pragma once

using namespace std;
using namespace cv;

class FeatureExtractor
{

public:

	void setImage(void *buf, int height, int width);
	cv::Mat getImage();
	void setKeypointsAndDescriptors(cv::Ptr<FeatureDetector> detector);
	void getDescriptorsAsString(char *);
	char *getDescriptorsAsString();
	void getDescriptorsAsArray(float* buf);
	void printDescriptors();
	Mat getDescriptors();
	vector<cv::KeyPoint> getKeypoints();

	FeatureExtractor();
	~FeatureExtractor();

private:
	cv::Mat image;
	Mat descriptors;
	vector<cv::KeyPoint> keyPoints;


};