#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <QGraphicsScene>
#include <Qlist>
#include "infoForAdvance.h"
#include <QObject>
class ParamSim;


class Environnement : public QObject {

	Q_OBJECT

private:
	QGraphicsScene * mScene;
	QList<infoForAdvance*> advanceInfoList;
	

public:
	Environnement(ParamSim *parameters);
	QGraphicsScene *scene() { return mScene; }
	Zombie* getClosestZombie(int index) { return advanceInfoList[index]->closestZombie; }
	Human* getClosestHuman(int index) { return advanceInfoList[index]->closestHuman; }
	double getDistanceToClosestZombie(int index) { return advanceInfoList[index]->distanceToClosestZombie; }
	double getDistanceToclosestHuman(int index) { return advanceInfoList[index]->distanceToClosestHuman; }

public slots:
	void advance(int phase);
};


#endif //ENVIRONNEMENT_H