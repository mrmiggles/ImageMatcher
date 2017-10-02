#pragma once

class Detector {
public:
	static Ptr<FeatureDetector> getDetector(int type);

	Detector();
	~Detector();
};