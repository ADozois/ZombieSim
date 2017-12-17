#include "Human.h"
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

Human::Human(double x, double y, int age, bool military, bool infected, QGraphicsItem *parent)
	:QHumanoid(x, y, parent),
	mAge{age},
	mSpecifier{nullptr},
	mVirus{nullptr}
{
	mBrushColor = mHumanColor;
	mPenColor = mHumanColor;
	mResistanceGenerator = new RandomNorm(mResistanceMean, mResistanceMean*mResistanceDeviation);
	mDeathAgeGenerator = new RandomNorm(mDeathAgeMean, mDeathAgeMean*mDeathAgeDeviation);
	mVirusResistance = mResistanceGenerator->Generate();
	mDeathAge = mDeathAgeGenerator->Generate();
    if(military)
	{
		mSpecifier = new Military();
	}
	if (infected)
	{
		mVirus = new Virus();
	}
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
