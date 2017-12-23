#include "QSimulationTab.h"
#include <iostream>
#include <Qgraphicsscene>
#include <Qgraphicsview>
#include <QAbstractButton>
#include "Environnement.h"
#include "ParamSim.h"
#include <QTimer>
<<<<<<< HEAD
#include "TimeLord.h"
=======
>>>>>>> master



#include <QDebug>


using namespace std;

QSimulationTab::QSimulationTab(QWidget *parent)
	: QWidget(parent)
{

	mTicString = new QString;

	//Layouts
	mMainLayout = new QHBoxLayout;
	mWorldLayout = new QHBoxLayout;

	mLeftLayout = new QVBoxLayout;
	mRightLayout = new QVBoxLayout;
	mSimGroupBoxLayout = new QVBoxLayout;
	mPushRightLayout = new QHBoxLayout;

	//Group box
	mSimGroupBox = new QGroupBox(tr("Simulation Controls"));
	//	mWorldGroupBox = new QGroupBox(tr("World View"));

	//Buttons
	mPlayButton = new QPushButton("Play");
	mPauseButton = new QPushButton("Pause");
	mStepButton = new QPushButton("Step");
	mStopButton = new QPushButton("Stop");

	//Labels
	mIconLabel = new QLabel();

	//Images
	QImage myImage;
	myImage.load(":/QSimZombie/Icon");
	mIconLabel->setPixmap(QPixmap::fromImage(myImage));
	mIconLabel->setAlignment(Qt::AlignRight);

	/* Simulation View goes in mLeftLayout */
	//Add simulation graphic view in this layout!*************************
<<<<<<< HEAD
	

	ParamSim *parameters;
	parameters = new ParamSim();

	Environnement *mMonde;
	mMonde = new Environnement(parameters);

	QGraphicsView* view = new QGraphicsView;
	view->setScene(mMonde->scene());
=======

	//QGraphicsView* view = new QGraphicsView;
	//mLeftLayout->addWidget(view);

	mView = new QGraphicsView;
	mLeftLayout->addWidget(mView);

>>>>>>> master
	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->setStretchFactor(mLeftLayout, 3); //Make the left layout occupy 3 times as much space as the right layout.


												   //QBrush greenBrush(Qt::green);
												   //QBrush blueBrush(Qt::blue);
												   //QPen outlinePen(Qt::black);
												   //outlinePen.setWidth(2);

												   //
												   //QGraphicsRectItem *rectangle = scene->addRect(0, 0, 80, 100, outlinePen, blueBrush);
												   ////scene->addRect(0, 0, 0.5, 0.5);


<<<<<<< HEAD
	
	mLeftLayout->addWidget(view);
	
=======

>>>>>>> master
	//connect(mPlayButton,&QPushButton::released, this, &fooo);


	//Add Buttons to groupbox
	mSimGroupBoxLayout->addWidget(mPlayButton);
	mSimGroupBoxLayout->addWidget(mPauseButton);
	mSimGroupBoxLayout->addWidget(mStepButton);
	mSimGroupBoxLayout->addWidget(mStopButton);
<<<<<<< HEAD
=======
	mPlayButton->setDisabled(true);
	mPauseButton->setDisabled(true);
	mStepButton->setDisabled(true);
	mStopButton->setDisabled(true);
>>>>>>> master



	//Current tic counter connect
	mTimeLord = new TimeLord;
<<<<<<< HEAD
	tim = mTimeLord->Timer();

	connect(tim, &QTimer::timeout, this, &QSimulationTab::updateTicLabel);
	
	

=======
	mTim = mTimeLord->Timer();

	connect(mTim, &QTimer::timeout, this, &QSimulationTab::updateTicLabel);
>>>>>>> master


	//Elapsed Tics
	mTicLabel = new QLabel("Elapsed tics: ");
<<<<<<< HEAD
	mTicValueLabel = new QLabel("");
=======
	mTicValueLabel = new QLabel("0");
	mTicValue = 0;
>>>>>>> master

	mTicLayout = new QHBoxLayout;
	mTicLayout->addWidget(mTicLabel);
	mTicLayout->addWidget(mTicValueLabel);

<<<<<<< HEAD
	
	
	
	






=======
>>>>>>> master


	//Set a groupbox inner layout
	mSimGroupBox->setLayout(mSimGroupBoxLayout);

	//Layout that's on the right for the buttons...
	//mRightLayout->addWidget(mIconLabel); //Icon on the right?
	mRightLayout->addStretch();
	mRightLayout->addLayout(mPushRightLayout);
	mPushRightLayout->addStretch();
	mPushRightLayout->addWidget(mSimGroupBox);



	mRightLayout->addLayout(mPushRightLayout);
	mRightLayout->addLayout(mTicLayout);
	mRightLayout->addStretch();



	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->addLayout(mRightLayout);

	//Connection for buttons
	connect(mPlayButton, &QPushButton::clicked, mTimeLord, &TimeLord::run);
	connect(mPlayButton, &QPushButton::clicked, mStepButton, &QPushButton::setEnabled);
	connect(mPlayButton, &QPushButton::clicked, mPauseButton, &QPushButton::setDisabled);
	connect(mPlayButton, &QPushButton::clicked, mStopButton, &QPushButton::setDisabled);

	connect(mPauseButton, &QPushButton::clicked, mTimeLord, &TimeLord::pause);
	connect(mPauseButton, &QPushButton::clicked, mStepButton, &QPushButton::setDisabled);

	connect(mStepButton, &QPushButton::clicked, mTimeLord, &TimeLord::step);

	connect(mStopButton, &QPushButton::clicked, mTimeLord, &TimeLord::stop);
	connect(mStopButton, &QPushButton::clicked, mPlayButton, &QPushButton::setEnabled);
	connect(mStopButton, &QPushButton::clicked, mStepButton, &QPushButton::setEnabled);
	connect(mStopButton, &QPushButton::clicked, mPauseButton, &QPushButton::setEnabled);



	//set this layout
	setLayout(mMainLayout);
}

void QSimulationTab::updateTicLabel() {


	mTicValue += 1;
<<<<<<< HEAD
	mTicString->number(mTicValue);
	mTicValueLabel->setText(*mTicString);

	qInfo() << "C++ Style Info Message";

}
=======
	mTicString->setNum(mTicValue);
	mTicValueLabel->setText(*mTicString);

	//qInfo() << "C++ Style Info Message";

}

void QSimulationTab::setWorld(Environnement * monde) {
	//monde->setScene();
	mView->setScene(monde->scene());
}

void QSimulationTab::disableStart()
{
	mPlayButton->setDisabled(true);
}

void QSimulationTab::activateStart()
{
	mPlayButton->setEnabled(true);
}
>>>>>>> master
