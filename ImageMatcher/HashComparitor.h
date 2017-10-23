#pragma once

#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/img_hash.hpp"

using namespace std;
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

template<typename T>
inline void HashComparitor<T>::test_one(const std::string & title, const Mat & a, const Mat & b)
{
}

template<typename T>
inline void HashComparitor<T>::compare(const Mat & hash1, const Mat & image)
{
	Mat hash2;
	func->compute(image, hash2);
	double  v = func->compare(hash1, hash2); //the lower the value for PHash the more similar
											 //double res = (1 - v) / 64.0;

	std::cout << "hash A: " << hash1 << endl;
	cout << "hash B: " << hash2 << endl;
	cout << "compare: " << v << endl;
}

template<typename T>
inline void HashComparitor<T>::retrieveHashFromMatImage(const Mat & image, Mat output)
{
	func->compute(image, output);
	cout << "computed hash" << output << endl;
}

template<typename T>
inline HashComparitor<T>::HashComparitor()
{
	func = T::create();
}

template<typename T>
inline HashComparitor<T>::~HashComparitor()
{
}
