#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/img_hash.hpp"
using namespace cv::img_hash;


template <typename T>
inline void test_one(const std::string &title, const Mat &a, const Mat &b)
{
	cout << "=== " << title << " ===" << endl;
	TickMeter tick;
	Mat hashA, hashB;
	Ptr<ImgHashBase> func;
	func = T::create();
	
	tick.reset(); tick.start();
	func->compute(a, hashA);
	tick.stop();
	cout << "compute1: " << tick.getTimeMilli() << " ms" << endl;
	tick.reset(); tick.start();
	func->compute(b, hashB);
	tick.stop();
	
	double  v = func->compare(hashA, hashB); //the lower the value for PHash the more similar
	double res = (1 - v) / 64.0;

	cout << "compute2: " << tick.getTimeMilli() << " ms" << endl;
	cout << "hash A: " << hashA << endl;
	cout << "hash B: " << hashB << endl;
	cout << "compare: " << v << endl;
	cout << "Result: " << res << endl << endl;;
	
}
