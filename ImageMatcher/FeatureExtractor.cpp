#include "stdafx.h"
#include "FeatureExtractor.h"

void FeatureExtractor::setImage(void * buf, int height, int width)
{
	image = Mat(height, width, CV_8UC3, Scalar(0, 0, 0));
	image.data = (uchar *)buf;
}

Mat FeatureExtractor::getImage()
{
	return image;
}

void FeatureExtractor::setKeypointsAndDescriptors(cv::Ptr<FeatureDetector> detector)
{
	detector->detectAndCompute(image, noArray(), keyPoints, descriptors);
}

void FeatureExtractor::getDescriptorsAsString(char *)
{
}



char * FeatureExtractor::getDescriptorsAsString()
{
	cout << "rows: " << descriptors.rows << endl;
	cout << "cols: " << descriptors.cols << endl;
	cout << "type: " << descriptors.type() << endl;
	std::string com = "";
	std::string text = "";
	char* descAsChar;

	for (int i = 0; i < descriptors.rows; i++) {
		for (int j = 0; j<descriptors.cols; j++) {
			//text += com + std::to_string(descriptorsA.at<float>(i, j)); //losing precision
			std::ostringstream out;
			out << descriptors.ptr(i)[j]; //descriptors.at<float>(i, j);
			text += com + out.str();
			out.clear();
			com = ",";
		}
	}
	descAsChar = new char[text.size() + 1];
	std::copy(text.begin(), text.end(), descAsChar);
	descAsChar[text.size()] = '\0';
	return descAsChar;
}

void FeatureExtractor::getDescriptorsAsArray(float *buf)
{
	buf = new float[descriptors.rows * descriptors.cols];
	int cols = descriptors.cols;
	for (int i = 0; i < descriptors.rows; i++) {
		for (int j = 0; j<descriptors.cols; j++) {
			buf[i* cols + j] = descriptors.ptr(i)[j]; 
		}
	}
}

void FeatureExtractor::printDescriptors()
{
	ofstream outfile("C:\\output\\dll_subjectDescriptors.txt", ios::out | std::ofstream::binary);
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(outfile.rdbuf()); //redirect std::cout to new.txt! 

	for (int i = 0; i < descriptors.rows; i++) {
		for (int j = 0; j<descriptors.cols; j++) {
			cout << descriptors.at<float>(i, j) << ",";
		}
	}
}

Mat FeatureExtractor::getDescriptors()
{
	return descriptors;
}

vector<cv::KeyPoint> FeatureExtractor::getKeypoints()
{
	return keyPoints;
}

FeatureExtractor::FeatureExtractor()
{
}

FeatureExtractor::~FeatureExtractor()
{
}
