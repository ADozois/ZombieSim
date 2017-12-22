#include "Zombie.h"
#include "QStatSim.h"
#include "Environnement.h"
#include <QObject>

RandomIntUnif * Zombie::mDeathGenerator{nullptr};
const int Zombie::mBegin{0};
const int Zombie::mEnd{100};
const int Zombie::mAttackThreshold{5};


Zombie::Zombie(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, QGraphicsItem * parent)
	: QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide, parent)
{
	mDeathGenerator = new RandomIntUnif(mBegin, mEnd);
	QStatSim::IncNbrZombie();
}

Zombie::~Zombie()
{
	QStatSim::DecNbrZombie();
}

void Zombie::advance(int phase, int const index)
{
	if (Energy() <= 0)
	{
		mEnvironnement->addDeathHumanoid(index);
	}
	else {
		if (mEnvironnement->getDistanceToclosestHuman(index) <= mEatingRange)
		{
			attack(mEnvironnement->getClosestHuman(index) , index);
		}
		else if (mEnvironnement->getDistanceToclosestHuman(index) <= mViewRaySq)
		{
			QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
			setDirectionTo(humanPos);
			moveInDirection(movementSpeed::run);

		}
		else if (mEnvironnement->getDistanceToClosestZombie(index) <= mEatingRange)
		{
			QPointF zombiPos = mEnvironnement->getClosestZombiPos(index);
			setDirectionFrom(zombiPos);
			moveInDirection(movementSpeed::walk);

		}
		else
		{
			//If no human are in sight, the zombi simply walk to the most populated are
			setDirectionTo(mEnvironnement->maxDensityPosition());
			moveInDirection(movementSpeed::walk);
		}
		//We reduce energy twice so the zombi looses energy while walking and also more energy when running
		ReduceEnergy();
		ReduceEnergy();
	}

}

void Zombie::advance(int phase)
{
	advance(phase, 0);
}

void Zombie::attack(Human * attackedHuman, int const index)
{
	if (attackedHuman->who()!=humanoideType::military)
	{
		//L'humain sera detruit à son tour du advance
		//Le zombi gagne de l'énergie pour avoir manger un humain
		this->AddEnergy(20);
	}
	else {
		//l'humain attaquer est un militaire, il y a combat
		if (mDeathGenerator->Generate() >= attackedHuman->Energy())
		{
			//Le zombi gagne
			this->AddEnergy(20);
			//On met l'energie du militaire à 0 pour qu'il soit éliminé à son tour.
			attackedHuman->ReduceEnergy(attackedHuman->Energy());
		}
		else {
			//Le zombi perd
			this->ReduceEnergy(Energy());
			mEnvironnement->addDeathHumanoid(index);
		}
	}
	
}
