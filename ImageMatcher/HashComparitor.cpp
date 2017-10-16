#include "stdafx.h"
#include "HashComparitor.h"

template<typename T>
void HashComparitor<T>::test_one(const std::string & title, const Mat & a, const Mat & b)
{
	cout << "=== " << title << " ===" << endl;
	TickMeter tick;
	Mat hashA, hashB;

	tick.reset(); tick.start();
	func->compute(a, hashA);
	tick.stop();
	cout << "compute1: " << tick.getTimeMilli() << " ms" << endl;
	tick.reset(); tick.start();
	func->compute(b, hashB);
	tick.stop();

	double  v = func->compare(hashA, hashB); //the lower the value for PHash the more similar
	//double res = (1 - v) / 64.0;

	cout << "compute2: " << tick.getTimeMilli() << " ms" << endl;
	cout << "hash A: " << hashA << endl;
	cout << "hash B: " << hashB << endl;
	cout << "compare: " << v << endl;
}

/*
 @param hash1 - precomputed hash
 @param image - cv::Mat version of an image
*/
template<typename T>
void HashComparitor<T>::compare(const Mat & hash1, const Mat & image)
{
	Mat hash2;
	func->compute(image, hash2);
	double  v = func->compare(hash1, hash2); //the lower the value for PHash the more similar
	//double res = (1 - v) / 64.0;

	cout << "hash A: " << hash1 << endl;
	cout << "hash B: " << hash2 << endl;
	cout << "compare: " << v << endl;
}

template<typename T>
void HashComparitor<T>::retrieveHashFromMatImage(const Mat & image, Mat output)
{
	func->compute(image, output);
	cout << "computed hash" << output << endl;
}

template<typename T>
HashComparitor<T>::HashComparitor()
{
	func = T::create();
}
template<typename T>
HashComparitor<T>::~HashComparitor()
{
}
