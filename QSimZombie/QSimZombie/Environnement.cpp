#include "Environnement.h"
#include <QGraphicsEllipseItem>
#include "RandomIntUnif.h"
#include "RandomNorm.h"
#include "ParamSim.h"
#include "QHumanoid.h"
#include "Human.h"
#include "Woman.h"


const int Environnement::mProbBegin{ 0 };
const int Environnement::mProbEnd{ 100 };


Environnement::Environnement(ParamSim *parameters)
	:mMeanPeopleDispertion{ 0 },
	mDevPeopleDispertion{ 10 }
{
	mScene = new QGraphicsScene(0, 0, 800, 200);
	mPeopleDispertion = new RandomNorm(mMeanPeopleDispertion, mDevPeopleDispertion);
	mProbabilityType = new RandomIntUnif(mProbBegin, mProbEnd);
	mHeightDispertion = new RandomIntUnif(0, ParamSim::SceneHeight());
	mWidthDispertion = new RandomIntUnif(0, ParamSim::SceneWidth());

	initializeWorld();

	


	//We create the initial scene with the parameters

	//A partir du nombre de ville, on détermine le nombre d,individus dans chaque ville (sépare également)

	//On Trouve la position (aléatoire) de chacune des villes

	//On peuple les villes en créant les humains dans chacun des groupes
	//Certain sont militaire, certain sont contaminé
}

Environnement::~Environnement()
{
	delete mPeopleDispertion;
	delete mHeightDispertion;
	delete mWidthDispertion;
}

inline void Environnement::CreateCity(int nbrPeople)
{
	QHumanoid * newItem{ nullptr };
	int x{ mWidthDispertion->Generate() };
	int y{ mHeightDispertion->Generate() };
	bool virus{ false };
	bool military{ false };
	int age{ 0 };
	for (int i = 0; i < nbrPeople; i++)
	{
		if (mProbabilityType->Generate() <= ParamSim::ProbInfection())
		{
			virus = true;
		}
		if (mProbabilityType->Generate() <= ParamSim::ProbNewMilitary())
		{
			military = true;
		}
		age = mProbabilityType->Generate();
		if (mProbabilityType->Generate() <= ParamSim::ProbWoman())
		{
			newItem = new Woman(x + mPeopleDispertion->Generate(), y + mPeopleDispertion->Generate(), age, military, virus);
		}
		else
		{
			newItem = new Human(x + mPeopleDispertion->Generate(), y + mPeopleDispertion->Generate(), age, military, virus);
		}
		mScene->addItem(newItem);
		military = false;
		virus = false;
	}
}

inline int Environnement::FindPeoplePerCity(int totalHuman, int nbrCity)
{
	return std::floor(totalHuman/nbrCity);
}

void Environnement::initializeWorld()
{
	int nbrPeoplePerCity = FindPeoplePerCity(ParamSim::NbrHuman(), ParamSim::NbrCity());

	for (int i = 0; i < ParamSim::NbrCity(); i++)
	{
		CreateCity(nbrPeoplePerCity);
	}
}


