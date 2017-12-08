#ifndef RANDOM_INT_UNIF_H
#define RANDOM_INT_UNIF_H

#include "QRandom.h"
class RandomIntUnif : public QRandom
{
public:
	RandomIntUnif(int a = 0, int b = 1);
	~RandomIntUnif();
	int A();
	int B();
	int Generate();

private:
	int mA;
	int mB;
	std::uniform_int_distribution<int> * mUniform;
};

#endif // !RANDOM_INT_UNIF_H

