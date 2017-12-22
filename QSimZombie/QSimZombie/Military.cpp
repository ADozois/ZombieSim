#include "Military.h"
#include "QStatSim.h"
#include "Human.h"
#include "Environnement.h"
#include "RandomIntUnif.h"

RandomIntUnif * Military::mKillGenerator{nullptr};
int Military::mKillTreshold{50};
const int Military::mBeginDist{0};
const int Military::mEndDist{100};
const int Military::mAgeBeginService{18};
const int Military::mAgeEndService{40};
const int Military::mFightEnergyLost{ 20 };

Military::Military()
	:mHumanLink{ nullptr }
{
	mKillGenerator = new RandomIntUnif(mBeginDist, mEndDist);
	QStatSim::IncNbrMilitaire();
}

Military::Military (Human * humanLink)
	:mHumanLink{humanLink}
{
	mKillGenerator = new RandomIntUnif(mBeginDist, mEndDist);	
	QStatSim::IncNbrMilitaire();
}

Military::~Military()
{
	QStatSim::DecNbrMilitaire();
}


Human::returnAdvance Military::advance(int phase, int const index)
{
	if (mHumanLink->IsDead())
	{
		mHumanLink->CurrentEnvironnement()->addDeathHumanoid(index);		

	}
	else
	{
		//Le zombi mange l'humain
		if (mHumanLink->CurrentEnvironnement()->getDistanceToClosestZombie(index) <= mHumanLink->eatingRange())
		{
			fightZombi(mHumanLink->CurrentEnvironnement()->getClosestZombie(index),index);
		}
		else if (mHumanLink->isTurning()) {
			//On est en train de tourner et on continue donc a faire le tournant pré-déterminé
			mHumanLink->makeTurn();
		}
		else if (mHumanLink->CurrentEnvironnement()->getDistanceToClosestZombie(index) <= mHumanLink->viewRaysq()) {
			//Zombi est visible, dependant de l'energi du militaire, il court vers ou a l'oposer du zombi				
			QPointF zombiPos = mHumanLink->CurrentEnvironnement()->getClosestZombiPos(index);
			if (mHumanLink->Energy() < 50)
			{
				mHumanLink->setDirectionFrom(zombiPos);
				mHumanLink->moveInDirection(Human::movementSpeed::run);
			}
			else
			{
				mHumanLink->setDirectionTo(zombiPos);
				mHumanLink->moveInDirection(Human::movementSpeed::run);
			}
			
		}
		else if (mHumanLink->CurrentEnvironnement()->getDistanceToclosestHuman(index) <= mHumanLink->eatingRange()) {
			//Si très près d'un autre humain, transmission de virus et s'éloigne de lui en marchant
			mHumanLink->transmitVirus(index);
			QPointF humanPos = mHumanLink->CurrentEnvironnement()->getClosestHumanPos(index);
			mHumanLink->setDirectionFrom(humanPos);
			mHumanLink->moveInDirection(Human::movementSpeed::walk);
		}
		else {
			// marche dans la direction qu'il allait déjà
			mHumanLink->moveInDirection(Human::movementSpeed::walk);
		}
		//L'humain viellit d'un tic (mois)
	mHumanLink->gainAge();
	}

	return Human::returnAdvance::noAction;
}

Human::returnAdvance Military::advance(int phase)
{
	return advance(phase, 0);
}


void Military::fightZombi(Zombie *zombie, int const index)
{
	if (!zombie->Energy)
	{
		//This means the zombi already lost the fight
		mHumanLink->ReduceEnergy(mFightEnergyLost);
	}
	else
	{
		if (mKillGenerator->Generate() >= mHumanLink->Energy()) {
			//Le zombi gagne le combat on met l'energie du militaire a 0
			mHumanLink->ReduceEnergy(mHumanLink->Energy());
			//On met le militaire dans la liste des humanoide mort
			mHumanLink->CurrentEnvironnement()->addDeathHumanoid(index);
		}
		else
		{
			//Le militaire gagne, on met l'energie du zombi a 0
			zombie->ReduceEnergy(zombie->Energy());
			//Le militaire perd de l'energi
			mHumanLink->ReduceEnergy(mFightEnergyLost);
		}
	}

}


bool Military::Kill(Zombie * zombie)
{
	if (mKillGenerator->Generate() >= mHumanLink->Energy()) {
		return false;
	}
	return true;
}

int Military::AgeBegin()
{
	return mAgeBeginService;
}

int Military::AgeEnd()
{
	return mAgeEndService;
}
