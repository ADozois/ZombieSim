#include "Woman.h"
#include "Children.h"

int Woman::mMaxChildren{ 5 };
const int Woman::mEndFertility{ 40 };
const int Woman::mFertilityTime{ 20 };

Woman::Woman(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age, HumanSpecifier *humainSpecifier, QGraphicsItem *parent)
	:Human(viewRay, rotationAngle, walkSpeed, runSpeed, currentEnvironnemnt, typeOfHumanoide, age, humainSpecifier, parent),
	mReproduction{false},
	mCountChildren{0},
	mTickRemaining{mFertilityTime}
{
}


Woman::~Woman()
{
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
