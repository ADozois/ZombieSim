#include "Military.h"
#include "RandomIntUnif.h"

RandomIntUnif * Military::mKillGenerator{nullptr};
int Military::mKillTreshold{50};
const int Military::mBeginDist{0};
const int Military::mEndDist{100};
const int Military::mAgeBeginService{18};
const int Military::mAgeEndService{40};

Military::Military()
{
	mKillGenerator = new RandomIntUnif(mBeginDist, mEndDist);
}

void Military::advance(int phase)
{
}

bool Military::Kill(Zombie * zombie)
{
	if (mKillGenerator->Generate() >= mKillTreshold) {
		return true;
	}
	return false;
}

int Military::AgeBegin()
{
	return mAgeBeginService;
}

int Military::AgeEnd()
{
	return mAgeEndService;
}
