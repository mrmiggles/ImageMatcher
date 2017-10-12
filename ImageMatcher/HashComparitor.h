#pragma once

#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/img_hash.hpp"

using namespace cv::img_hash;


template <typename T>
class HashComparitor {

public:
	void test_one(const std::string &title, const Mat &a, const Mat &b);
	void compare(const Mat &hash1, const Mat &image);
	void retrieveHashFromMatImage(const Mat &image, Mat output);

	HashComparitor();
	~HashComparitor();

private:
	Ptr<ImgHashBase> func;
};

