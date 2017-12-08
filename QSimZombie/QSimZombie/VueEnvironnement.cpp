#include "VueEnvironnement.h"


VueEnvironnement::VueEnvironnement(Environnement * scene,int height, int width, QObject *parent)
	:mViewHeight{height},mViewWidth{width}
{
	this->setScene(scene);


}