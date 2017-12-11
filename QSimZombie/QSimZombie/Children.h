#ifndef CHILDREN_H
#define CHILDREN_H

#include "HumanSpecifier.h"

class RandomIntUnif;
class Woman;

class Children : public HumanSpecifier
{
public:
	Children();
	~Children() = default;

	void advance(int phase) override;
	int AgeBegin();
	int AgeEnd();
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



