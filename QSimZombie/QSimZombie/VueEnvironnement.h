#ifndef VUE_ENVIRONNEMENT_H
#define VUE_ENVIRONNEMENT_H

#include <qgraphicsview.h>
#include "Environnement.h"

class VueEnvironnement : public QGraphicsView {

	Q_OBJECT

private:
	int mViewHeight;
	int mViewWidth;

public:
	VueEnvironnement(Environnement * scene, int height, int width, QObject *parent = Q_NULLPTR);


};




#endif //VUE_ENVIRONNEMENT_H
