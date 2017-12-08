#include "RandomNorm.h"



RandomNorm::RandomNorm(double mean, double std_dev)
	:mMean{mean},
	mStd{std_dev}
{
	mNormal = new std::normal_distribution<double>(mMean, mStd);
}


RandomNorm::~RandomNorm()
{
}

double RandomNorm::Mean()
{
	return mMean;
}

double RandomNorm::Std()
{
	return mStd;
}

double RandomNorm::Generate()
{
	return (*mNormal)(QRandom::Mt());
}
