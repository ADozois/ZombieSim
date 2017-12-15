#ifndef TIME_LORD_H
#define TIME_LORD_H

#include <qwidget.h>

class QTimer;
class ParamSim;
class Environnement;
class QGraphicsView;

class TimeLord {


private:
	QTimer *mTimer;
	QGraphicsView *mVue;
	Environnement *mMonde;
	ParamSim *mParameters;

	static const int mDefaultTime{ 1000 };

public:
	//TimeLord(QWidget *parent = Q_NULLPTR);
	TimeLord();
	void run();
	void pause();
	void stop();
	void step();

};

#endif //TIME_LORD_H
