#ifndef MILITARY_H
#define MILITARY_H

#include "HumanSpecifier.h"

class Zombie;
class RandomIntUnif;

class Military : public HumanSpecifier
{
public:
	Military();
	~Military() = default;

	void advance(int phase) override;
	bool Kill(Zombie * zombie);
	int AgeBegin();
	int AgeEnd();

private:
	static RandomIntUnif * mKillGenerator;
	static int mKillTreshold;

	static const int mBeginDist;
	static const int mEndDist;
	static const int mAgeBeginService;
	static const int mAgeEndService;

};

#endif // !MILITARY_H


