#include "Children.h"
#include "RandomIntUnif.h"
#include "Woman.h"
#include "Human.h"
#include "Environnement.h"
#include "QStatSim.h"

RandomIntUnif * Children::mDistribution{nullptr};
//int Children::mBegin{0};
//int Children::mEnd{100};
bool Children::mBecomeMilitary{ false };
bool Children::mBecomeWoman{ false };
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

void Children::advance(int phase, int index)
{
	if (mHumanLink->IsDead())
	{
		mMother->LosingChild(this);
		mHumanLink->CurrentEnvironnement()->addDeathHumanoid(index);
		
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
			//L'enfant devient adulte
			//On doit suprimer l'attribu enfant, mais garder l'humain...
			//On doit aussi regarder s'il devient militaire

		}
		else {
			mHumanLink->setDirectionTo(mMother->pos());
			mHumanLink->moveInDirection(Human::movementSpeed::walk);
		}
		//L'humain viellit d'un tic (mois)
		//++mAge;  Trouver le moyen d'acceder � l'age de l'humain
	}
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

void Children::setMother(Woman * mother)
{
	mMother = mother;
}

