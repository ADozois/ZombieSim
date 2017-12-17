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
	QList<infoForAdvance*> mAdvanceInfoList;
	QList<QGraphicsItem *> mDeathList;

	void getInformation(QHumanoid * comparedHumanoide, qreal distance, infoForAdvance &infoToFill);
	
	static const double mDensityRadius;
public:
	Environnement(ParamSim *parameters);
	QGraphicsScene *scene() { return mScene; }
	Zombie* getClosestZombie(int index) { return mAdvanceInfoList[index]->closestZombie; }
	Human* getClosestHuman(int index) { return mAdvanceInfoList[index]->closestHuman; }
	qreal getDistanceToClosestZombie(int index) { return mAdvanceInfoList[index]->distanceToClosestZombie; }
	qreal getDistanceToclosestHuman(int index) { return mAdvanceInfoList[index]->distanceToClosestHuman; }
	int getHumainDensity(int index) { return mAdvanceInfoList[index]->numberOfCloseHumain; }
	void addDeathHumanoid(int index);

public slots:
	void advance();
};


#endif //ENVIRONNEMENT_H