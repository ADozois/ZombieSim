#ifndef CHILDREN_H
#define CHILDREN_H

#include "HumanSpecifier.h"

class RandomIntUnif;
class Woman;

class Children : public HumanSpecifier
{
public:
	Children();
	Children(Woman * mother);
	~Children() = default;

	void advance(int phase) override;
	void advance(int phase, int index) override;
	static int AgeBegin();
	static int AgeEnd();
	void LosingMother();
	Woman * Mother();



private:
	Woman * mMother;

	static RandomIntUnif * mDistribution;
	static int mBegin;
	static int mEnd;
	static int mMilitaryProb;
	static int mWomanProb;
	static bool mBecomeMilitary;
	static bool mBecomeWoman;
	
	static const int mAgeBeginChildren;
	static const int mAgeEndChildren;
};

#endif // !CHILDREN_H



