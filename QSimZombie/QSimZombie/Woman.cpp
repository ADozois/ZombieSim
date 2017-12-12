#include "Woman.h"
#include "Children.h"

int mMaxChildren{ 5 };
const int mEndFertility{ 40 };
const int mFertilityTime{ 20 };

Woman::Woman(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, int age, QGraphicsItem *parent)
	:Human(viewRay, rotationAngle, walkSpeed, runSpeed, age, parent),
	mReproduction{false},
	mCountChildren{0},
	mTickRemaining{mFertilityTime}
{
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
