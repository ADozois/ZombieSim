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

	//A partir du nombre de ville, on d�termine le nombre d,individus dans chaque ville (s�pare �galement)

	//On Trouve la position (al�atoire) de chacune des villes

	//On peuple les villes en cr�ant les humains dans chacun des groupes
	//Certain sont enfant, certain sont militaire, certain sont contamin�
}

void Environnement::advance()
{
		//On calcul les donn�es qui nous seront n�cessaire pour chacun des humano�de dans la scene
		mAdvanceInfoList.clear();
		//On r�cup�re tous les items de la scene (donc tous les humanoides)
		QList<QGraphicsItem *> currentListOfHumanoides = mScene->items();
		//On alloue la m�moire pour le tableau qui contiendra la distance entre chaque humanoide
		qreal *distTable = new qreal[currentListOfHumanoides.size()*currentListOfHumanoides.size()];

		//On rempli la table avec la distance entre chaque �l�ments

		//On regarde les distance avec le premier hors de la boucle pour �vit� de toujours faire la v�rification si c'est le premier (pour �vit� de recalculer les distance d�j� calcul�
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
			//On choisit l'humanoide regard�
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
		

		//On appel le advance de tous les humano�des
		for (int humanoidIndex{ 0 }; humanoidIndex < currentListOfHumanoides.size(); ++humanoidIndex)
		{
			QHumanoid * comparedHumanoide = dynamic_cast<QHumanoid *>(currentListOfHumanoides[humanoidIndex]);
			comparedHumanoide->advance(0, humanoidIndex);
		}

		//On d�truit les humanoides qui sont mort ce tic-ci
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