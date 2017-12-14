#include "RandomIntUnif.h"



RandomIntUnif::RandomIntUnif(int a, int b)
	:mA{a},
	mB{b}
{
	mUniform = new std::uniform_int_distribution<int>(mA, mB);
}


RandomIntUnif::~RandomIntUnif()
{
}

int RandomIntUnif::A()
{
	return mA;
}

int RandomIntUnif::B()
{
	return mB;
}

int RandomIntUnif::Generate()
{
	return (*mUniform)(QRandom::Mt());
}
