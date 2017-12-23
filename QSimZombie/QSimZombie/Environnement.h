#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <QGraphicsScene>
#include <Qlist>
#include "infoForAdvance.h"
#include <QObject>

class ParamSim;
class RandomNorm;
class RandomIntUnif;



class Environnement : public QObject {

	Q_OBJECT

private:
	QGraphicsScene * mScene;
	QList<infoForAdvance*> mAdvanceInfoList;
	QList<QGraphicsItem *> mDeathList;
	RandomNorm * mPeopleDispertion;
	RandomIntUnif * mProbabilityType;
	RandomIntUnif * mHeightDispertion;
	RandomIntUnif * mWidthDispertion;
	RandomIntUnif * mPopulationDistribution;
	double mMeanPeopleDispertion;
	double mDevPeopleDispertion;
	QPointF mMaxDensityPosition;
	int mMaxDensityValue;

	void CreateCity(int nbrPeople);
	int FindPeoplePerCity(int totalHuman, int nbrCity);

	static const int mProbBegin;
	static const int mProbEnd;

	void getInformation(QHumanoid * comparedHumanoide, qreal distance, infoForAdvance &infoToFill);
	
	static const double mDensityRadius;
public:
	Environnement(ParamSim *parameters);
	~Environnement();
	void initializeWorld();
	QGraphicsScene *scene() { return mScene; }
	Zombie* getClosestZombie(int index) { return mAdvanceInfoList[index]->closestZombie; }
	Human* getClosestHuman(int index) { return mAdvanceInfoList[index]->closestHuman; }
	qreal getDistanceToClosestZombie(int index) { return mAdvanceInfoList[index]->distanceToClosestZombie; }
	qreal getDistanceToclosestHuman(int index) { return mAdvanceInfoList[index]->distanceToClosestHuman; }
	QPointF getClosestZombiPos(int index) { return mAdvanceInfoList[index]->currentPositionClosestZombi; }
	QPointF getClosestHumanPos(int index) { return mAdvanceInfoList[index]->currentPositionClosestHuman; }
	int getHumainDensity(int index) { return mAdvanceInfoList[index]->numberOfCloseHumain; }
	QPointF maxDensityPosition() { return mMaxDensityPosition; }
	void addDeathHumanoid(int index);

public slots:
	void advance();
};


#endif //ENVIRONNEMENT_H