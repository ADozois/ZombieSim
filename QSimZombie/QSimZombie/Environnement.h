#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <QGraphicsScene>
#include <qlist.h>

class Environnement : public QGraphicsScene {

	Q_OBJECT

private:
	//QList<Humanoide> mEntities;
	QList<QGraphicsItem*> mEntities;
	int mEntityCount;

public:
	Environnement(QObject *parent = Q_NULLPTR);
	//void addHumanoide(Humanoide newHumanoide);
	void addHumanoide(QGraphicsItem * newHumanoide);


};


#endif //ENVIRONNEMENT_H