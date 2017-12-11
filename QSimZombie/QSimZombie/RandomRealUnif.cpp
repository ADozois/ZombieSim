#include "RandomRealUnif.h"



RandomRealUnif::RandomRealUnif(double a, double b)
	:mA{ a },
	mB{ b }
{
	mUniform = new std::uniform_real_distribution<double>(mA, mB);
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

double RandomRealUnif::Generate(double a, double b)
{
	return std::uniform_real_distribution<double>{a, b}(std::mt19937(std::random_device()));
}
