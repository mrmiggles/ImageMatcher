#pragma once

#include "stdafx.h"

class Matcher {
public:
	
	vector<DMatch> matches;
	vector<vector<DMatch>> nn_matches;
	vector<DMatch> good_matches;
	vector<KeyPoint> matched1, matched2, inliers1, inliers2;

	void setMatcher(int type);
	cv::Ptr<DescriptorMatcher>  getMatcher();
	void findMatches(Mat descriptorsA, Mat descriptorsB);
	void findknnMatches(Mat descriptorsA, Mat descriptorsB);
	bool checkIfGoodMatch();
	bool checkIfGoodMatch(float nndrRatio);
	bool checkGoodMatchWHomography(Mat subject, vector<KeyPoint> kpts1, Mat scene, vector<KeyPoint> kpts2, Mat subjectDescriptors);
	void paintMatches(Mat subject, Mat scene, vector<cv::KeyPoint> keypointsA, vector<cv::KeyPoint> keypointsB);
	void paintGoodMatches(Mat subject, Mat scene, vector<cv::KeyPoint> keypointsA, vector<cv::KeyPoint> keypointsB);
	void drawGoodMatchesWHomography(Mat img_object, Mat img_scene, vector<KeyPoint> keypoints_object, vector<KeyPoint> keypoints_scene, Mat homography);

	Matcher();
	~Matcher();

private:
	const float inlier_threshold = 2.5f; // Distance threshold to identify inliers
	const double akaze_thresh = 3e-4; // AKAZE detection threshold set to locate about 1000 keypoints
	const double ransac_thresh = 2.5f; // RANSAC inlier threshold
	const double nn_match_ratio = 0.7f; // Nearest-neighbour matching ratio

	/*stuff for working directory */
	char working_directory[MAX_PATH + 1];
	DWORD dwRet;	

	Ptr<DescriptorMatcher> matcher;
	char *mt; //text description of matcher

};