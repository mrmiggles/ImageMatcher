#pragma once

#include "stdafx.h"

class Matcher {
public:
	
	void setMatcher(int type);
	cv::Ptr<DescriptorMatcher>  getMatcher();
	void findMatches(Mat descriptorsA, Mat descriptorsB, vector<DMatch> &matches);
	void findknnMatches(Mat descriptorsA, Mat descriptorsB, vector<vector<DMatch>> &nn_matches);
	bool checkIfGoodMatch(vector<vector<DMatch>> &nn_matches, vector<DMatch> &good_matches);
	bool checkIfGoodMatch(float nndrRatio, vector<vector<DMatch>> &nn_matches, vector<DMatch> &good_matches, int *goodMatches);
	bool checkGoodMatchWHomography(Mat subject, vector<KeyPoint> kpts1, Mat scene, vector<KeyPoint> kpts2, Mat subjectDescriptors, vector<DMatch> &matches, vector<DMatch> &good_matches);
	void paintMatches(Mat subject, Mat scene, vector<cv::KeyPoint> keypointsA, vector<cv::KeyPoint> keypointsB);
	void paintGoodMatches(Mat subject, Mat scene, vector<cv::KeyPoint> keypointsA, vector<cv::KeyPoint> keypointsB, vector<DMatch> &good_matches);
	void drawGoodMatchesWHomography(Mat img_object, Mat img_scene, vector<KeyPoint> keypoints_object, vector<KeyPoint> keypoints_scene, vector<DMatch> &good_matches, Mat homography);

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