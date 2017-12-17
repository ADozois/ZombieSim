#include "Environnement.h"

#include <QGraphicsEllipseItem>

const double Environnement::mDensityRadius{ 3.0 };

Environnement::Environnement(ParamSim *parameters)
{
	mScene = new QGraphicsScene;


	//On cree 10 cercles juste pour dire
	for (int i = 0; i < 10; ++i)
	{
		QGraphicsEllipseItem * newItem = new QGraphicsEllipseItem(-50 + i * 20, -50 + 1 * 20, 10, 10);
		mScene->addItem(newItem);
	}

	


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
		infoForAdvance* firstHumanoideInfo;
		for (int j{ 1 }; j<currentListOfHumanoides.size(); ++j)
		{
			QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[j]);
			distTable[j] = pow(currentHumanoide->pos().x() - comparedHumanoide->pos().x(), 2) + pow(currentHumanoide->pos().y() - comparedHumanoide->pos().y(), 2);
			distTable[j*currentListOfHumanoides.size()] = distTable[j];
			getInformation(comparedHumanoide, distTable[j], *firstHumanoideInfo);
			
		}
		//On place l'information pour cet humanoide dans le tableau
		mAdvanceInfoList.append(firstHumanoideInfo);


		for (int i{ 1 };i<currentListOfHumanoides.size();++i)
		{
			//On choisit l'humanoide regardé
			QHumanoid * currentHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[i]);
			infoForAdvance* currentInfo;

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
		}

	}
	else {
		if (distance < infoToFill.distanceToClosestHuman)
		{
			infoToFill.closestHuman = dynamic_cast<Human *>(comparedHumanoide);
			infoToFill.distanceToClosestHuman = distance;
		}
		if (distance < mDensityRadius)
		{
			++infoToFill.numberOfCloseHumain;
		}
	}

}


void Environnement::addDeathHumanoid(int index) 
{ 
	QList<QGraphicsItem *> currentListOfHumanoides = mScene->items();
	mDeathList.append(currentListOfHumanoides[index]);

}