#include "Human.h"
#include "Environnement.h"
#include "Children.h"
#include "Military.h"
#include "Virus.h"
#include <QPainter>

RandomNorm * Human::mResistanceGenerator{nullptr};
const double Human::mResistanceMean{50.0};
const double Human::mResistanceDeviation{0.2};
RandomNorm * Human::mDeathAgeGenerator{nullptr};
const double Human::mDeathAgeMean{80.0};
const double Human::mDeathAgeDeviation{0.3};
const QColor Human::mHumanColor{ 241, 140, 135 };


Human::Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age, bool military, bool infected, QGraphicsItem *parent)
	:QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide,parent),
	mAge{age},
	mSpecifier{nullptr},
	mVirus{nullptr},
	mWillBeocmeMilitary{false}
{
	BaseHumanInit();
    if(military)
	{
		CreateMilitary();
	}
	if (infected)
	{
		CreateVirus();
	}
}

Human::Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, bool becomeMilitary, bool infected, QGraphicsItem *parent)
	:QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide, parent),
	mAge{ 0 },
	mSpecifier{ nullptr },
	mVirus{ nullptr },
	mWillBeocmeMilitary{ becomeMilitary }
{
	BaseHumanInit();
	if (infected)
	{
		CreateVirus();
	}
	CreateChild();
}

Human::~Human()
{
	DeleteSpecifier();
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

void Human::MilitaryPainter(QPainter * painter)
{
	Military * military = dynamic_cast<Military*>(mSpecifier);
	if (military)
	{
		mBrushColor = Qt::darkGreen;
		mPenColor = Qt::darkGreen;
	}
}

void Human::ChildrenPainter(QPainter * painter)
{
	Children * child = dynamic_cast<Children*>(mSpecifier);
	if (child)
	{
		mBrushColor = Qt::darkYellow;
		mPenColor = Qt::darkYellow;
	}
}

void Human::InfectedPainter(QPainter * painter)
{
	if (mVirus)
	{
		mPenColor = Qt::black;
	}
}

void Human::DeleteSpecifier()
{
	if (mSpecifier)
	{
		delete[] mSpecifier;
		mSpecifier = nullptr;
	}
}

void Human::BaseHumanInit()
{
	mBrushColor = mHumanColor;
	mPenColor = mHumanColor;
	mResistanceGenerator = new RandomNorm(mResistanceMean, mResistanceMean*mResistanceDeviation);
	mDeathAgeGenerator = new RandomNorm(mDeathAgeMean, mDeathAgeMean*mDeathAgeDeviation);
	mVirusResistance = mResistanceGenerator->Generate();
	mDeathAge = mDeathAgeGenerator->Generate();
}

void Human::CreateMilitary()
{
	if (mSpecifier)
	{
		throw std::exception("Le pointeur est déjà utilisé par une autre instance");
	}
	else
	{
		mSpecifier = new Military();
	}
}

void Human::CreateVirus()
{
	if (!mVirus)
	{
		mVirus = new Virus();
	}
}

void Human::CreateChild()
{
	if (mSpecifier)
	{
		throw std::exception("Le pointeur est déjà utilisé par une autre instance");
	}
	else
	{
		mSpecifier = new Children();
	}
}

void Human::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (mSpecifier)
	{
		MilitaryPainter(painter);
		ChildrenPainter(painter);
	}
	else
	{
		painter->setBrush(mBrushColor);
	}
	InfectedPainter(painter);
	InitializeVisual(painter);
}

bool Human::IsBecomingZombie(bool biteByZombie)
{
	if (mVirus->IsBecomingZombit() || biteByZombie)
	{
		DeleteSpecifier();
		return true;
	}
	return false;
}

void Human::IsBecomingAdult()
{
	if (mAge >= Children::AgeEnd())
	{
		DeleteSpecifier();
		if (mWillBeocmeMilitary)
		{
			CreateMilitary();
		}
	}
}

void Human::IsRetiring()
{
	if (mAge >= Military::AgeEnd())
	{
		DeleteSpecifier();
	}
}
