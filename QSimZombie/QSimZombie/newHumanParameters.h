#ifndef NEW_HUMAN_PARAMETERS
#define NEW_HUMAN_PARAMETERS

#include <QGraphicsItem>

//Structure used for new human or women creation. Passing this structure instead of all the separate parameters
struct newHumanParameters {
	qreal avrgRunSpeed;
	qreal avrgWalkSpeed;
	qreal avrgViewRay;
	qreal avrgFertility;
	qreal avrgVirusResistance;
	qreal avrgDeathAge;
	bool isMilitary;
	bool isInfected;

};

#endif //NEW_HUMAN_PARAMETERS