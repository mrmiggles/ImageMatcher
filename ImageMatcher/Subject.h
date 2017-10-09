#pragma once

class Subject
{
public:
	void setImage(Mat sI);
	Mat getImage();

	void setKeypoints(vector<cv::KeyPoint> kp);
	void setDescriptorsFromFloatBuffer(float *kpts, int rows, int cols, int matType);
	void addToKeyPoints(float x, float y);
	Mat getDescriptors();
	vector<cv::KeyPoint> getKeypoints();
	void printDescriptors();
	void checkSubjectKeypoints();

	void cleanUp();
	Subject();
	~Subject();

private:
	Mat subjectImage;
	vector<cv::KeyPoint> keypoints;
	Mat descriptors;

};