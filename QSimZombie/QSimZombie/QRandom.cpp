#include "QRandom.h"

std::random_device QRandom::mRd;
std::mt19937 QRandom::mMt(QRandom::mRd());


std::random_device & QRandom::Rd()
{
	return mRd;
}

std::mt19937 & QRandom::Mt()
{
	return mMt;
}


