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
	
	static const int mAgeBeginChildren;
	static const int mAgeEndChildren;
};

#endif // !CHILDREN_H



