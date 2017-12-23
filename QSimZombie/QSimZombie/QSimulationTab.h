#ifndef Q_SIMULATION_TAB_H
#define Q_SIMUlATION_TAB_H

#include <QtWidgets/QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QImage>
#include "TimeLord.h"



class QSimulationTab : public QWidget
{
	Q_OBJECT


public:
	QSimulationTab(QWidget *parent = nullptr);

	QPushButton *getPlayButton() { return mPlayButton; }
	QPushButton *getStopButton() { return mStopButton; }

<<<<<<< HEAD


	QTimer* tim;
public slots:

	void updateTicLabel();

	

protected:

=======
	void setWorld(Environnement * monde);


	
	public slots:

	void updateTicLabel();
	void disableStart();
	void activateStart();




protected:

	QTimer * mTim;
>>>>>>> master
	int mTicValue;
	QString* mTicString;

	TimeLord* mTimeLord;
<<<<<<< HEAD
	
	QLabel* mTicLabel;
	QLabel* mTicValueLabel;
	QHBoxLayout* mTicLayout;

	
=======

	QLabel* mTicLabel;
	QLabel* mTicValueLabel;
	QHBoxLayout* mTicLayout;
	QGraphicsView* mView;

>>>>>>> master

	//Layouts
	QHBoxLayout *mMainLayout;
	QVBoxLayout *mRightLayout;
	QVBoxLayout *mLeftLayout;

	QVBoxLayout *mSimGroupBoxLayout;
	QHBoxLayout *mPushRightLayout;
	QHBoxLayout *mWorldLayout;
	QHBoxLayout *mWorldLayoutB;
	//Buttons
	QPushButton *mPlayButton;
	QPushButton *mPauseButton;
	QPushButton *mStepButton;
	QPushButton *mStopButton;

	//GroupBox
	QGroupBox *mSimGroupBox;
	//QGroupBox *mWorldGroupBox;

	//Label
	QLabel *mIconLabel;
<<<<<<< HEAD
	
=======

>>>>>>> master


};
#endif //Q_SIMUlATION_TAB_H