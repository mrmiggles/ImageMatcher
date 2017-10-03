#pragma once

class Subject
{
public:
	void setImage(Mat sI);
	Mat getImage();

	void setKeypoints(vector<cv::KeyPoint> kp);
	void addToKeyPoints(float x, float y);
	vector<cv::KeyPoint> getKeypoints();
	void printDescriptors();
	void checkSubjectKeypoints();

	void setDescriptors(Mat ds);
	void MatToBytes();
	cv::Mat BytesToMat();
	Mat getDescriptors();
	void clearDescAsChar();

	void cleanUp();
	Subject();
	~Subject();

private:
	Mat subjectImage;
	vector<cv::KeyPoint> keypointsA;
	Mat descriptorsA;

};