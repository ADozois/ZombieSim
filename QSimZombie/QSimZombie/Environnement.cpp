#include "Environnement.h"

#include <QGraphicsEllipseItem>



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

void Environnement::advance(int phase)
{
	if (!phase)
	{
		//On calcul les données qui nous seront nécessaire pour chacun des humanoïde dans la scene
		advanceInfoList.clear();
		//On récupère tous les items de la scene (donc tous les humanoides)
		QList<QGraphicsItem *> currentListOfHumanoides = mScene->items();
		//On alloue la mémoire pour le tableau qui contiendra la distance entre chaque humanoide
		qreal *distTable = new qreal[currentListOfHumanoides.size()*currentListOfHumanoides.size()];

		//On rempli la table avec la distance entre chaque éléments

		//On regarde les distance avec le premier hors de la boucle pour évité de toujours faire la vérification si c'est le premier (pour évité de recalculer les distance déjà calculé
		QHumanoid * currentHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[0]);		
		for (int j{ 0 }; j<currentListOfHumanoides.size(); ++j)
		{
			infoForAdvance* currentInfo;
			QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[j]);
			distTable[j] = pow(currentHumanoide->pos().x() - comparedHumanoide->pos().x(), 2) + pow(currentHumanoide->pos().y() - comparedHumanoide->pos().y(), 2);
			if (comparedHumanoide->who() == ZOMBI)
			{
				if (distTable[j] < currentInfo->distanceToClosestZombie)
				{
					currentInfo->closestZombie = dynamic_cast<Zombie *>(comparedHumanoide);
					currentInfo->distanceToClosestZombie = distTable[j];
				}
				
			}
			else {
				if (distTable[j] < currentInfo->distanceToClosestHuman)
				{
					currentInfo->closestHuman = dynamic_cast<Human *>(comparedHumanoide);
					currentInfo->distanceToClosestHuman = distTable[j];
				}
			}
		}


		for (int i{ 1 };i<currentListOfHumanoides.size();++i)
		{
			//On choisit l'humanoide regardé
			QHumanoid * currentHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[i]);

			for (auto const& j : currentListOfHumanoides)
			{

			}
		}
		

		//On appel le advance de tous les humanoïdes
	}
}
