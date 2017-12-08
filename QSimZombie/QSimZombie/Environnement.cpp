#include "Environnement.h"
#include <QGraphicsEllipseItem>



Environnement::Environnement(ParamSim *parameters)
{
	mScene = new QGraphicsScene;


	QBrush greenBrush(Qt::green);
	QPen outlinePen(Qt::black);
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