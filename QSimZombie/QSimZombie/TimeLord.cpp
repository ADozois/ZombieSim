#include "TimeLord.h"
#include <QGraphicsView>
#include <Qtimer>
#include "Environnement.h"
#include "ParamSim.h"
#include "QParametersTab.h"
#include <QObject>

TimeLord::TimeLord()
{


	mTimer = new QTimer();
	mVue = new QGraphicsView();
	mParameters = new ParamSim();
	mMonde = new Environnement(mParameters);

	QObject::connect(mTimer, &QTimer::timeout, mMonde, &Environnement::advance);

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

	QTimer::singleShot(mDefaultTime, mMonde->scene(), &QGraphicsScene::advance);

}