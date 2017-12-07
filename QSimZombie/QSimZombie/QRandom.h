#ifndef Q_RANDOM_H
#define Q_RANDOM_H

#include <random>

class QRandom
{
public:
	QRandom();
	virtual ~QRandom();
	virtual double GenerateReal() = 0;
	virtual int GenerateInt() = 0;

private:
	static std::random_device mRd;
	static std::mt19937 mMt;
};

#endif // !Q_RANDOM_H




