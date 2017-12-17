#ifndef INFO_FOR_ADVANCE_H
#define INFO_FOR_ADVANCE_H
#include "Human.h"
#include "Zombie.h"

struct infoForAdvance {
	Zombie *closestZombie{ nullptr };
	Human *closestHuman{ nullptr };
	qreal distanceToClosestZombie{ DBL_MAX };
	qreal distanceToClosestHuman{ DBL_MAX };
	int numberOfCloseHumain{ 0 };
};


#endif //INFO_FOR_ADVANCE_H
