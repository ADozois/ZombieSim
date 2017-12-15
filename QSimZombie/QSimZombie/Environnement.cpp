#include "Environnement.h"
#include <QGraphicsEllipseItem>
#include "RandomIntUnif.h"
#include "RandomNorm.h"
#include "ParamSim.h"
#include "QHumanoid.h"
#include "Human.h"



Environnement::Environnement(ParamSim *parameters)
	:mMeanPeopleDispertion{ 0 },
	mDevPeopleDispertion{ 10 }
{
	mScene = new QGraphicsScene(0, 0, 800, 200);
	mPeopleDispertion = new RandomNorm(mMeanPeopleDispertion, mDevPeopleDispertion);
	mHeightDispertion = new RandomIntUnif(0, ParamSim::SceneHeight());
	mWidthDispertion = new RandomIntUnif(0, ParamSim::SceneWidth());

	//On cree 10 cercles juste pour dire
	
	
	initializeWorld();

	


	//We create the initial scene with the parameters

	//A partir du nombre de ville, on détermine le nombre d,individus dans chaque ville (sépare également)

	//On Trouve la position (aléatoire) de chacune des villes

	//On peuple les villes en créant les humains dans chacun des groupes
	//Certain sont enfant, certain sont militaire, certain sont contaminé
}

Environnement::~Environnement()
{
	delete mPeopleDispertion;
	delete mHeightDispertion;
	delete mWidthDispertion;
}

inline void Environnement::CreateCity(int nbrPeople)
{
	int x = mWidthDispertion->Generate();
	int y = mHeightDispertion->Generate();
	for (int i = 0; i < nbrPeople; i++)
	{
		QHumanoid * newItem = new Human(x + mPeopleDispertion->Generate(),y + mPeopleDispertion->Generate());
		mScene->addItem(newItem);
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


