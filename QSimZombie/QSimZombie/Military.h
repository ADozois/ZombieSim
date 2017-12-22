#ifndef MILITARY_H
#define MILITARY_H

#include "HumanSpecifier.h"

class Zombie;
class RandomIntUnif;

class Military : public HumanSpecifier
{
public:

	Military();
	Military(Human *humanLink);

	~Military();

	Human::returnAdvance advance(int phase) override;
	Human::returnAdvance advance(int phase, int const index) override;
	bool Kill(Zombie * zombie);
	void fightZombi(Zombie *zombie, int const index);
	static int AgeBegin();
	static int AgeEnd();

private:
	Human * mHumanLink;
	static RandomIntUnif * mKillGenerator;
	static int mKillTreshold;

	static const int mBeginDist;
	static const int mEndDist;
	static const int mAgeBeginService;
	static const int mAgeEndService;
	static const int mFightEnergyLost;

};

#endif // !MILITARY_H


