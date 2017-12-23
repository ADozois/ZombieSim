#ifndef TIME_LORD_H
#define TIME_LORD_H

#include <qwidget.h>
#include <QObject>


class QTimer;
class ParamSim;
class Environnement;
class QGraphicsView;

class TimeLord : public QObject{


private:
	QTimer *mTimer;
	QGraphicsView *mVue;
	Environnement *mMonde;
	ParamSim *mParameters;

	static const int mDefaultTime{ 1000 };

public slots:
	void actOfGood(QPoint pos);


public:
	TimeLord();
	void run();
	void pause();
	void stop();
	void step();
	QTimer * Timer() { return mTimer; }
	void createWorld();
	Environnement * Monde() { return mMonde; };

};

#endif //TIME_LORD_H
