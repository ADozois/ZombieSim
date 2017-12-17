#include "Human.h"
#include "Environnement.h"

RandomNorm * Human::mResistanceGenerator{nullptr};
const double Human::mResistanceMean{50.0};
const double Human::mResistanceDeviation{0.2};
RandomNorm * Human::mDeathAgeGenerator{nullptr};
const double Human::mDeathAgeMean{80.0};
const double Human::mDeathAgeDeviation{0.3};

Human::Human(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide,int age, HumanSpecifier *humainSpecifier, QGraphicsItem *parent)
	:QHumanoid(viewRay, rotationAngle, walkSpeed, runSpeed, currentEnvironnemnt,typeOfHumanoide,  parent),
	mAge{age}
{
	mResistanceGenerator = new RandomNorm(mResistanceMean, mResistanceMean*mResistanceDeviation);
	mDeathAgeGenerator = new RandomNorm(mDeathAgeMean, mDeathAgeMean*mDeathAgeDeviation);
	mVirusResistance = mResistanceGenerator->Generate();
	mDeathAge = mDeathAgeGenerator->Generate();

	mSpecifier = humainSpecifier;
}

Human::~Human()
{
	if (mSpecifier)
	{
		delete mSpecifier;
	}
}

void Human::advance(int phase, int index)
{
	if (!phase)
	{
		//On fait le advance du specifier si l'humain à un specifier
		if (mSpecifier)
		{
			mSpecifier->advance(phase,index);
		}
		else {
			if (IsDead())
			{
				mEnvironnement->addDeathHumanoid(index);
			}
			else
			{
				//mEnvironnement
				//	//On fait la logique pour zombi le plus proche et humain le plus proche
				//	if (mEnvironnement->getDistanceToClosestZombie() == )
			}

		}
	}
}

void Human::advance(int phase)
{
	advance(phase, 0);
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
