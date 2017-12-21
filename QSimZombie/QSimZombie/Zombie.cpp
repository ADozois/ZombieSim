#include "Zombie.h"
#include <QObject>

RandomIntUnif * Zombie::mDeathGenerator{nullptr};
const int Zombie::mBegin{0};
const int Zombie::mEnd{10};
const int Zombie::mAttackThreshold{5};


Zombie::Zombie(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, QGraphicsItem * parent)
	: QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide, parent)
{
	mDeathGenerator = new RandomIntUnif(mBegin, mEnd);
}

void Zombie::advance(int phase, int index)
{
}

void Zombie::advance(int phase)
{
	advance(phase, 0);
}

bool Zombie::attack(QGraphicsItem * human)
{
	if (mDeathGenerator->Generate() >= mAttackThreshold)
	{
		if (human)
		{
			return true;
		}
	}
	return false;
}
