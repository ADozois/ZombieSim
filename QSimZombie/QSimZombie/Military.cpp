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


void Military::advance(int phase, int const index)
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
		else if (mHumanLink->mIsTurning) {
			//On est en train de tourner et on continue donc a faire le tournant pré-déterminé
			mMovementDirection = mTurningDirection[mTurningAtPosition];
			++mTurningAtPosition;
			moveInDirection(movementSpeed::run);
			if (mTurningAtPosition > mNumberOfTurningDirection)
			{
				mIsTurning = false;
			}
		}
		else if (mHumanLink->CurrentEnvironnement()->getDistanceToClosestZombie(index) <= mViewRaySq) {
			//Zombi est visible, court dans le sens inverse					
			QPointF zombiPos = mHumanLink->CurrentEnvironnement()->getClosestZombiPos(index);
			setDirectionFrom(zombiPos);
			moveInDirection(movementSpeed::run);
		}
		else if (mHumanLink->CurrentEnvironnement()->getDistanceToclosestHuman(index) <= mEatingRange) {
			//Si très près d'un autre humain, transmission de virus et s'éloigne de lui en marchant
			VirusTransmission();
			QPointF humanPos = mHumanLink->CurrentEnvironnement()->getClosestHumanPos(index);
			setDirectionFrom(humanPos);
			moveInDirection(movementSpeed::walk);
		}
		else if (mHumanLink->CurrentEnvironnement()->getDistanceToclosestHuman(index) <= mViewRaySq) {
			//Si humain visible, marche vers lui
			QPointF humanPos = mHumanLink->CurrentEnvironnement()->getClosestHumanPos(index);
			setDirectionTo(humanPos);
			moveInDirection(movementSpeed::walk);
		}
		else {
			//Si humain et zombi trop loin pour les voir, marche dans la direction qu'il allait déjà
			moveInDirection(movementSpeed::walk);
		}
		//L'humain viellit d'un tic (mois)
	mHumanLink->gainAge();
	}
}

void Military::advance(int phase)
{
	advance(phase, 0);
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
