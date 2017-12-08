#include "RandomRealUnif.h"



RandomRealUnif::RandomRealUnif(double a, double b)
{
	mUniform = new std::uniform_real_distribution<double>(a, b);
}


RandomRealUnif::~RandomRealUnif()
{
}

double RandomRealUnif::A()
{
	return mA;
}

double RandomRealUnif::B()
{
	return mB;
}

double RandomRealUnif::Generate()
{
	return (*mUniform)(QRandom::Mt());
}
