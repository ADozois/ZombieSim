#pragma once
#include "QRandom.h"
class RandomNorm : public QRandom
{
public:
	RandomNorm(double mean = 0.0, double std_dev = 1.0);
	~RandomNorm();
	double Mean();
	double Std();
	double Generate();

	static double Generate(double mean, double dev);

private:
	double mMean;
	double mStd;
	std::normal_distribution<double> * mNormal;
};

