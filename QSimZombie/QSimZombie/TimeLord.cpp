#include "TimeLord.h"
#include <QGraphicsView>
#include <Qtimer>
#include "Environnement.h"
#include "ParamSim.h"
#include "QParametersTab.h"
#include <QObject>
#include <QTimer>
TimeLord::TimeLord()
	:mMonde{nullptr}
{
	mTimer = new QTimer();
	mVue = new QGraphicsView();
	mParameters = new ParamSim();
	mMonde = new Environnement(mParameters);


}



void TimeLord::run() {

	

	mTimer->start(mDefaultTime);

}


void TimeLord::pause() {
	mTimer->stop();

}


void TimeLord::stop() {
	mTimer->stop();

}


void TimeLord::step() {

	//QTimer::singleShot(mDefaultTime, mMonde->scene(), &Environnement::advance);

}

<<<<<<< HEAD
=======
void TimeLord::createWorld()
{
	mMonde->prepWorld();
	mMonde->initializeWorld();
	QObject::connect(mTimer, &QTimer::timeout, mMonde, &Environnement::advance);
}
>>>>>>> master
