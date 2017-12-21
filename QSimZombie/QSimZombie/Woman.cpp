#include "Woman.h"
#include "Children.h"
#include "QStatSim.h"
#include <QPainter>

int Woman::mMaxChildren{ 5 };
const int Woman::mEndFertility{ 40 };
const int Woman::mFertilityTime{ 20 };
const QColor Woman::mWomanColor{ 242, 229, 135 };


Woman::Woman(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age, bool military, bool infection, QGraphicsItem *parent)
	:Human(x, y, currentEnvironnemnt, typeOfHumanoide, age, military, infection,parent),
	mReproduction{false},
	mCountChildren{0},
	mTickRemaining{mFertilityTime}
{
	mBrushColor = mWomanColor;
	mPenColor = mWomanColor;
	QStatSim::IncNbrFemme();
}

Woman::Woman(double x, double y, Environnement * currentEnvironnemnt, humanoideType typeOfHumanoide, bool military, bool infection, QGraphicsItem * parent)
	:Human(x, y, currentEnvironnemnt, typeOfHumanoide, military, infection, parent),
	mReproduction{ false },
	mCountChildren{ 0 },
	mTickRemaining{ mFertilityTime }
{
	mBrushColor = mWomanColor;
	mPenColor = mWomanColor;
	QStatSim::IncNbrFemme();

}

Woman::Woman(double x, double y, Environnement * currentEnvironnemnt, humanoideType typeOfHumanoide, qreal runSpeed, qreal walkSpeed, qreal viewRay, bool military, bool infection, QGraphicsItem * parent)
	:Human(x, y, currentEnvironnemnt, typeOfHumanoide, runSpeed, walkSpeed, viewRay, military, infection, parent),
	mReproduction{ false },
	mCountChildren{ 0 },
	mTickRemaining{ mFertilityTime }
{
	mBrushColor = mWomanColor;
	mPenColor = mWomanColor;
	QStatSim::IncNbrFemme();

}


Woman::~Woman()
{
	QStatSim::DecNbrFemme();
}

void Woman::advance(int phase, int index)
{
}

void Woman::advance(int phase)
{
	advance(phase, 0);
}

Children * Woman::GiveBirth()
{	
	Children * newChild = new Children(this);
	mListChildren.append(newChild);
	mCountChildren++;
	mReproduction = true;
	mTickRemaining = mFertilityTime;
	return newChild;
}

int Woman::CountChildren()
{
	return mCountChildren;
}

bool Woman::Reproduction()
{
	if (mReproduction == false) {
		return false;
	}
	if (mTickRemaining != mFertilityTime)
	{
		return false;
	}
	return true;
}

void Woman::LosingChild(Children * child)
{
	int i = 0;
	for (auto & children : mListChildren)
	{
		if (children == child)
		{
			mListChildren.removeAt(i);
		}
		i++;
	}
}

