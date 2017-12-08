#include "Environnement.h"




Environnement::Environnement(QObject *parent)
	:mEntityCount{0}
{

}



void Environnement::addHumanoide(QGraphicsItem * newHumanoide) {
	
	QBrush greenBrush(Qt::green);
	QPen outlinePen(Qt::black);

	mEntities.push_back(newHumanoide);
	this->addItem(newHumanoide);
	++mEntityCount;
}