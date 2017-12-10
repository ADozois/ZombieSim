#include "Human.h"

RandomNorm * mResistanceGenerator{nullptr};
const double mResistanceMean{50.0};
const double mResistanceDeviation{0.2};
RandomNorm * mDeathAgeGenerator{nullptr};
const double mDeathAgeMean{80.0};
const double mDeathAgeDeviation{0.3};

Human::Human(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, int age = 0, QGraphicsItem *parent)
	:QHumanoid(viewRay, rotationAngle, walkSpeed, runSpeed, parent),
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
