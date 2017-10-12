#include "stdafx.h"
#include "MatchResult.h"

vector<DMatch>& MatchResult::getMatches()
{
	return matches;
}

vector<DMatch>& MatchResult::getGoodMatches()
{
	return good_matches;
}

vector<vector<DMatch>>& MatchResult::get_nn_matches()
{
	return nn_matches;
}

void MatchResult::resetVectors()
{

	good_matches.clear();
	good_matches.shrink_to_fit();

	//simply clearing might not be good enough for the nested
	nn_matches.clear();
	nn_matches.shrink_to_fit();

	matched1.clear();
	matched1.shrink_to_fit();

	matched2.clear();
	matched2.shrink_to_fit();

	inliers1.clear();
	inliers1.shrink_to_fit();

	inliers2.clear();
	inliers2.shrink_to_fit();
}

MatchResult::MatchResult()
{
}

MatchResult::~MatchResult()
{
}