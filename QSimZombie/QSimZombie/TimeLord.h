#ifndef TIME_LORD_H
#define TIME_LORD_H

#include <QWidget>

class QTimer;
class ParamSim;
class Environnement;
class QGraphicsView;

class TimeLord : public QWidget
{
	Q_OBJECT

private:
	QTimer *mTimer;
	QGraphicsView *mVue;
	Environnement *mMonde;
	ParamSim *mParameters;

	static const int mDefaultTime{ 100 };

public:
	TimeLord();	
	QTimer * Timer() { return mTimer; }
	void createWorld();
	Environnement * Monde() { return mMonde; }

public slots:

	void run();
	void pause();
	void stop();
	void step();

};

#endif //TIME_LORD_H
