#ifndef RANDOM_REAL_UNIF
#define RANDOM_REAL_UNIF

#include "QRandom.h"

class RandomRealUnif : public QRandom
{
public:
	RandomRealUnif(double a = 0.0, double b = 1.0);
	~RandomRealUnif();
	double A();
	double B();
	double Generate();

private:
	double mA;
	double mB;
	std::uniform_real_distribution<double> *mUniform;
};


#endif // !RANDOM_REAL_UNIF

