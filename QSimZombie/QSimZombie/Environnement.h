#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <QGraphicsScene>
#include <Qlist>

class ParamSim;
class RandomNorm;
class RandomIntUnif;


class Environnement {


private:
	QGraphicsScene * mScene;
	RandomNorm * mPeopleDispertion;
	RandomIntUnif * mProbabilityType;
	RandomIntUnif * mHeightDispertion;
	RandomIntUnif * mWidthDispertion;
	RandomIntUnif * mPopulationDistribution;
	double mMeanPeopleDispertion;
	double mDevPeopleDispertion;

	void CreateCity(int nbrPeople);
	int FindPeoplePerCity(int totalHuman, int nbrCity);
	void initializeWorld();

	static const int mProbBegin;
	static const int mProbEnd;

public:
	Environnement(ParamSim *parameters);
	~Environnement();
	QGraphicsScene *scene() { return mScene; }
};


#endif //ENVIRONNEMENT_H