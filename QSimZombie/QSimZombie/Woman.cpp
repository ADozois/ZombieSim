#include "Woman.h"
#include "Children.h"
#include <QPainter>

int Woman::mMaxChildren{ 5 };
const int Woman::mEndFertility{ 40 };
const int Woman::mFertilityTime{ 20 };
const QColor Woman::mWomanColor{ 242, 229, 135 };

Woman::Woman(double x, double y, int age, bool military, QGraphicsItem *parent)
	:Human(x, y, age, military,parent),
	mReproduction{false},
	mCountChildren{0},
	mTickRemaining{mFertilityTime}
{
	mPainterColor = mWomanColor;
}


Woman::~Woman()
{
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

