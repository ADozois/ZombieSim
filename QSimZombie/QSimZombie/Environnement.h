#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <QGraphicsScene>
#include <Qlist>
class ParamSim;

class Environnement {


private:
	QGraphicsScene * mScene;
	

public:
	Environnement(ParamSim *parameters);
	QGraphicsScene *scene() { return mScene; }
};


#endif //ENVIRONNEMENT_H