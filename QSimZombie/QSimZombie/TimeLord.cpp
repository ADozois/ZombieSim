#include "TimeLord.h"
#include <QGraphicsView>
#include <Qtimer>
#include "Environnement.h"
#include "ParamSim.h"

#include <QObject>

TimeLord::TimeLord()
	:mMonde{nullptr}
{
	mTimer = new QTimer();
	mVue = new QGraphicsView();
	mParameters = new ParamSim();
	


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

void TimeLord::createWorld()
{
	mMonde = new Environnement(mParameters);
	mMonde->initializeWorld();
	QObject::connect(mTimer, &QTimer::timeout, mMonde, &Environnement::advance);
}
