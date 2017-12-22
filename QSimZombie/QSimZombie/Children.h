#ifndef CHILDREN_H
#define CHILDREN_H

#include "HumanSpecifier.h"

class RandomIntUnif;
class Woman;
class Human;

class Children : public HumanSpecifier
{
public:
	Children();
	Children(Woman * mother, Human * humanLink);
	~Children();

	HumanSpecifier::returnAdvance advance(int phase) override;
	HumanSpecifier::returnAdvance advance(int phase, int const index) override;
	static int AgeBegin();
	static int AgeEnd();
	void LosingMother();
	Woman * Mother();
	void setMother(Woman * mother);



private:
	Woman * mMother;
	Human * mHumanLink; //To have all the info of the human the humanSpecifier is attached to

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



