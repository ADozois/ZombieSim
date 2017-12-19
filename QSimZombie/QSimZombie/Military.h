#ifndef MILITARY_H
#define MILITARY_H

#include "HumanSpecifier.h"

class Zombie;
class RandomIntUnif;

class Military : public HumanSpecifier
{
public:
	Military();
	~Military();

	void advance(int phase) override;
	void advance(int phase, int index) override;
	bool Kill(Zombie * zombie);
	static int AgeBegin();
	static int AgeEnd();

private:
	static RandomIntUnif * mKillGenerator;
	static int mKillTreshold;

	static const int mBeginDist;
	static const int mEndDist;
	static const int mAgeBeginService;
	static const int mAgeEndService;

};

#endif // !MILITARY_H


