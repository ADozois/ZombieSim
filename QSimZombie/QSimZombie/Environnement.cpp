#include "Environnement.h"
#include <QGraphicsEllipseItem>
#include "RandomIntUnif.h"
#include "RandomNorm.h"
#include "ParamSim.h"
#include "QHumanoid.h"
#include "Human.h"
#include "Woman.h"


const double Environnement::mDensityRadius{ 200 };
const int Environnement::mProbBegin{ 216 };
const int Environnement::mProbEnd{ 1200 };

Environnement::Environnement(ParamSim *parameters)
	:mMeanPeopleDispertion{ 0 },
	mDevPeopleDispertion{ 10 },
	mMaxDensityPosition{0,0},
	mMaxDensityValue{ 0 }
{
	mScene = new QGraphicsScene(0, 0, ParamSim::SceneWidth(), ParamSim::SceneHeight());
	mPeopleDispertion = new RandomNorm(mMeanPeopleDispertion, mDevPeopleDispertion);
	mProbabilityType = new RandomIntUnif(mProbBegin, mProbEnd);

	//We create the initial scene with the parameters

	//A partir du nombre de ville, on détermine le nombre d,individus dans chaque ville (sépare également)

	//On Trouve la position (aléatoire) de chacune des villes

	//On peuple les villes en créant les humains dans chacun des groupes
	//Certain sont enfant, certain sont militaire, certain sont contaminé
}

void Environnement::advance()
{
		//On calcul les données qui nous seront nécessaire pour chacun des humanoïde dans la scene
		mAdvanceInfoList.clear();
		//On récupère tous les items de la scene (donc tous les humanoides)
		QList<QGraphicsItem *> currentListOfHumanoides = mScene->items();
		//On alloue la mémoire pour le tableau qui contiendra la distance entre chaque humanoide
		qreal *distTable = new qreal[currentListOfHumanoides.size()*currentListOfHumanoides.size()];

		//On rempli la table avec la distance entre chaque éléments

		//On regarde les distance avec le premier hors de la boucle pour évité de toujours faire la vérification si c'est le premier (pour évité de recalculer les distance déjà calculé
		QHumanoid * currentHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[0]);
		infoForAdvance* firstHumanoideInfo{ nullptr };
		for (int j{ 1 }; j<currentListOfHumanoides.size(); ++j)
		{
			QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[j]);
			distTable[j] = pow(currentHumanoide->pos().x() - comparedHumanoide->pos().x(), 2) + pow(currentHumanoide->pos().y() - comparedHumanoide->pos().y(), 2);
			distTable[j*currentListOfHumanoides.size()] = distTable[j];
			getInformation(comparedHumanoide, distTable[j], *firstHumanoideInfo);
			
		}
		//On place l'information pour cet humanoide dans le tableau
		mMaxDensityValue = firstHumanoideInfo->numberOfCloseHumain;
		mMaxDensityPosition = currentHumanoide->pos();
		mAdvanceInfoList.append(firstHumanoideInfo);


		for (int i{ 1 };i<currentListOfHumanoides.size();++i)
		{
			//On choisit l'humanoide regardé
			QHumanoid * currentHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[i]);
			infoForAdvance* currentInfo{ nullptr };

			for (int j{ i - 1 }; j>-1; --j)
			{
				QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[j]);
				getInformation(comparedHumanoide, distTable[i*currentListOfHumanoides.size() + j], *currentInfo);

			}

			for (int j{ i+1 }; j<currentListOfHumanoides.size(); ++j)
			{
				QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[j]);
				distTable[i*currentListOfHumanoides.size()+j] = pow(currentHumanoide->pos().x() - comparedHumanoide->pos().x(), 2) + pow(currentHumanoide->pos().y() - comparedHumanoide->pos().y(), 2);
				distTable[j*currentListOfHumanoides.size() + i] = distTable[i*currentListOfHumanoides.size() + j];
				getInformation(comparedHumanoide, distTable[i*currentListOfHumanoides.size() + j], *currentInfo);
			}

			if (currentInfo->numberOfCloseHumain > mMaxDensityValue)
			{
				mMaxDensityValue = currentInfo->numberOfCloseHumain;
				mMaxDensityPosition = currentHumanoide->pos();
			}
			mAdvanceInfoList.append(currentInfo);
		}
		

		//On appel le advance de tous les humanoïdes
		for (int humanoidIndex{ 0 }; humanoidIndex < currentListOfHumanoides.size(); ++humanoidIndex)
		{
			QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[humanoidIndex]);
			comparedHumanoide->advance(0, humanoidIndex);
		}

		//On détruit les humanoides qui sont mort ce tic-ci
		for (auto deadIndex : mDeathList)
		{
			delete deadIndex;
			deadIndex = nullptr;
		}
		//On claire la list
		mDeathList.clear();
}


void Environnement::getInformation(QHumanoid * comparedHumanoide, qreal distance, infoForAdvance &infoToFill) {
	if (comparedHumanoide->who() == QHumanoid::humanoideType::zombi)
	{
		if (distance< infoToFill.distanceToClosestZombie)
		{
			infoToFill.closestZombie = dynamic_cast<Zombie *>(comparedHumanoide);
			infoToFill.distanceToClosestZombie = distance;
			infoToFill.currentPositionClosestZombi = comparedHumanoide->pos();
		}

	}
	else {
		if (distance < infoToFill.distanceToClosestHuman)
		{
			infoToFill.closestHuman = dynamic_cast<Human *>(comparedHumanoide);
			infoToFill.distanceToClosestHuman = distance;
			infoToFill.currentPositionClosestHuman = comparedHumanoide->pos();
		}
		if (distance < mDensityRadius)
		{
			++infoToFill.numberOfCloseHumain;
		}
	}

}

void Environnement::prepWorld()
{
	QList<QGraphicsItem *> entity = mScene->items();
	if (entity.size() > 0)
	{
		for (auto & item: entity)
		{
			mScene->removeItem(item);
			delete[] item;
			item = nullptr;
		}
	}
}

void Environnement::setScene()
{
	mScene->setSceneRect(0, 0, ParamSim::SceneWidth(), ParamSim::SceneHeight());
}


void Environnement::addDeathHumanoid(int index) 
{ 
	QList<QGraphicsItem *> currentListOfHumanoides = mScene->items();
	mDeathList.append(currentListOfHumanoides[index]);

}

Environnement::~Environnement()
{
	delete mPeopleDispertion;
}

inline void Environnement::CreateCity(int nbrPeople)
{
	QHumanoid * newItem{ nullptr };
	int x{ RandomIntUnif::Generate(0, ParamSim::SceneWidth()) };
	int y{ RandomIntUnif::Generate(0, ParamSim::SceneHeight()) };
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
			newItem = new Woman(x + mPeopleDispertion->Generate(), y + mPeopleDispertion->Generate(),this,QHumanoid::humanoideType::woman, age, military, virus);
		}
		else
		{
			newItem = new Human(x + mPeopleDispertion->Generate(), y + mPeopleDispertion->Generate(), this, QHumanoid::humanoideType::human, age, military, virus);
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
