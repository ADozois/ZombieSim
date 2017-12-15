#include "Zombie.h"
#include <QObject>

RandomIntUnif * Zombie::mDeathGenerator{nullptr};
const int Zombie::mBegin{0};
const int Zombie::mEnd{10};
const int Zombie::mAttackThreshold{5};

Zombie::Zombie(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, QGraphicsItem * parent)
	: QHumanoid(viewRay, rotationAngle, walkSpeed, runSpeed, parent)
{
	mDeathGenerator = new RandomIntUnif(mBegin, mEnd);
}

void Zombie::advance(int phase)
{
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
