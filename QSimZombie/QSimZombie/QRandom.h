#ifndef Q_RANDOM_H
#define Q_RANDOM_H

#include <random>

class QRandom
{
public:
	QRandom() = default;
	virtual ~QRandom() = default;
	std::random_device &Rd();
	std::mt19937 &Mt();

private:
	static std::random_device mRd;
	static std::mt19937 mMt;
};

#endif // !Q_RANDOM_H




