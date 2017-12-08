#pragma once
#include "QRandom.h"
class RandomNorm : public QRandom
{
public:
	RandomNorm(double mean = 0.0, double std_dev = 0.0);
	~RandomNorm();
	double Mean();
	double Std();
	double Generate();

private:
	double mMean;
	double mStd;
	std::normal_distribution<double> * mNormal;
};

