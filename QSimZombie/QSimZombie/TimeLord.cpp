#include "TimeLord.h"
#include <QGraphicsView>
#include <Qtimer>
#include "Environnement.h"
#include "ParamSim.h"


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

void TimeLord::createWorld()
{
	mMonde->prepWorld();
	mMonde->initializeWorld();
	QObject::connect(mTimer, &QTimer::timeout, mMonde, &Environnement::advance);
}

void TimeLord::actOfGood(QPoint pos)
{
	mMonde->createZombie(pos);
}
