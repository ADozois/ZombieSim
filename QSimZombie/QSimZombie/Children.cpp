#include "Children.h"
#include "RandomIntUnif.h"
#include "Woman.h"
#include "Human.h"
#include "Environnement.h"
#include "QStatSim.h"


const int Children::mAgeBeginChildren{ 0 };
const int Children::mAgeEndChildren{ 215 };

Children::Children()
	:Children(nullptr,nullptr)
{	
	QStatSim::IncNbrEnfant();
}

Children::Children(Woman * mother, Human * humanLink)
	:mMother{mother},
	mHumanLink{ humanLink }

{
	
	QStatSim::IncNbrEnfant();
}

Children::~Children()
{
	QStatSim::DecNbrEnfant();
}

HumanSpecifier::returnAdvance Children::advance(int phase, int index)
{
	if (mHumanLink->IsDead())
	{
		mMother->LosingChild(this);
		mHumanLink->CurrentEnvironnement()->addDeathHumanoid(index);
		mHumanLink->becomeZombie();
		
	}
	else
	{
		//Le zombi mange l'humain
		if (mHumanLink->CurrentEnvironnement()->getDistanceToClosestZombie(index) <= mHumanLink->eatingRange())
		{
			mMother->LosingChild(this);
			mHumanLink->CurrentEnvironnement()->addDeathHumanoid(index);			
			
		}
		else if (mHumanLink->Age() > mAgeEndChildren)
		{
			return HumanSpecifier::returnAdvance::newAdult;

		}
		else {
			mHumanLink->setDirectionTo(mMother->pos());
			mHumanLink->moveInDirection(Human::movementSpeed::walk, mHumanLink->CurrentEnvironnement()->getHumainDensity(index) + 1);
		}
		//L'humain viellit d'un tic (mois)
		mHumanLink->gainAge();
	}
	return HumanSpecifier::returnAdvance::noAction;
}

HumanSpecifier::returnAdvance Children::advance(int phase)
{
	return advance(phase, 0);
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

void Children::setMother(Woman * mother)
{
	mMother = mother;
}

