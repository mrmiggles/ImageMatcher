#pragma once
#include "stdafx.h"

class MatchResult
{
public:
	
	vector<DMatch>& getMatches();
	vector<DMatch>& getGoodMatches();
	vector<vector<DMatch>>& get_nn_matches();
	void resetVectors();
	MatchResult();
	~MatchResult();

private:
	vector<DMatch> matches;
	vector<vector<DMatch>> nn_matches;
	vector<DMatch> good_matches;
	vector<KeyPoint> matched1, matched2, inliers1, inliers2;	
};