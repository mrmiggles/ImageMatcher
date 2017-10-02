// ImageMatcher.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern "C" {

	Ptr<FeatureDetector> detector;
	Matcher matcher;
	FeatureExtractor fe;
	char *mt;

	/* Set detector type */
	DECLDIR void setDetector(int type) {
		detector = Detector::getDetector(type);
	}

	DECLDIR void setMatcher(int type) {
		matcher.setMatcher(type);
	}

	DECLDIR void extractFeaturesFromImage(void *buf, int h, int w) {
		fe.setImage(buf, h, w);
		if (!detector) setDetector(0);
		fe.setKeypointsAndDescriptors(detector);
	}

	DECLDIR char* getDescriptorsAsString() {
		if (fe.getImage().empty() && !fe.getImage().data) return NULL;

		return fe.getDescriptorsAsString();
	}

	DECLDIR char* getKeypointsAsString() {
		if (fe.getImage().empty() && !fe.getImage().data) return NULL;
		return NULL;
	}

	DECLDIR void testMatching(void *buf1, int h1, int w1, void *buf2, int h2, int w2) {
		Matcher matcher;
		matcher.setMatcher(1);

		FeatureExtractor im1;
		im1.setImage(buf1, h1, w1);
		im1.setKeypointsAndDescriptors(detector);

		FeatureExtractor im2;
		im2.setImage(buf2, h2, w2);
		im2.setKeypointsAndDescriptors(detector);
		
		matcher.findknnMatches(im1.getDescriptors(), im2.getDescriptors());
		bool ev = matcher.checkIfGoodMatch();
		matcher.paintGoodMatches(im1.getImage(), im2.getImage(), im1.getKeypoints(), im2.getKeypoints());

		im1.printDescriptors();

	}

}
