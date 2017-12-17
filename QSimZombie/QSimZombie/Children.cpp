#include "Children.h"
#include "RandomIntUnif.h"
#include "Woman.h"

RandomIntUnif * Children::mDistribution{nullptr};
int Children::mBegin{0};
int Children::mEnd{100};
int Children::mMilitaryProb{20};
int Children::mWomanProb{50};
bool Children::mBecomeMilitary{ false };
bool Children::mBecomeWoman{ false };
const int Children::mAgeBeginChildren{ 0 };
const int Children::mAgeEndChildren{ 18 };

Children::Children()
	:Children(nullptr)
{	
}

Children::Children(Woman * mother)
	:mMother{mother}
{
	mDistribution = new RandomIntUnif(mBegin, mEnd);
	if (mDistribution->Generate() >= mWomanProb)
	{
		mBecomeWoman = true;
	}
	else
	{
		if (mDistribution->Generate() >= mMilitaryProb)
		{
			mBecomeMilitary = true;
		}
	}
}

void Children::advance(int phase, int index)
{
}

void Children::advance(int phase)
{
	advance(phase, 0);
}

int Children::AgeBegin()
{
	return mAgeBeginChildren;
}

int Children::AgeEnd()
{
	return mAgeEndChildren;
}

void Children::LosingMother()
{
	mMother = nullptr;
}

Woman * Children::Mother()
{
	return mMother;
}

