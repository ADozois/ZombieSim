#include "QRandom.h"

std::random_device QRandom::mRd;
std::mt19937 QRandom::mMt(QRandom::mRd());


QRandom::QRandom()
{
	
}

QRandom::~QRandom()
{

}


