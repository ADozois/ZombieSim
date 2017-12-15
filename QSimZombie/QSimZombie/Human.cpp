#include "Human.h"

RandomNorm * Human::mResistanceGenerator{nullptr};
const double Human::mResistanceMean{50.0};
const double Human::mResistanceDeviation{0.2};
RandomNorm * Human::mDeathAgeGenerator{nullptr};
const double Human::mDeathAgeMean{80.0};
const double Human::mDeathAgeDeviation{0.3};

Human::Human(double x, double y, int age, QGraphicsItem *parent)
	:QHumanoid(x, y, parent),
	mAge{age}
{
	mResistanceGenerator = new RandomNorm(mResistanceMean, mResistanceMean*mResistanceDeviation);
	mDeathAgeGenerator = new RandomNorm(mDeathAgeMean, mDeathAgeMean*mDeathAgeDeviation);
	mVirusResistance = mResistanceGenerator->Generate();
	mDeathAge = mDeathAgeGenerator->Generate();
}

Human::~Human()
{
}

void Human::advance(int phase)
{
}

bool Human::IsDead()
{
	if (mAge == mDeathAge) {
		return true;
	}
	return false;
}

void Human::Reproduction()
{
}

int Human::Age()
{
	return mAge;
}

int Human::DeathAge()
{
	return mDeathAge;
}

int Human::VirusResistance()
{
	return mVirusResistance;
}

bool Human::VirusTransmission()
{
	//TODO implemente
	return false;
}
