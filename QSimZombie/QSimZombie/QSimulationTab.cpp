#include "QSimulationTab.h"
#include <iostream>
#include <Qgraphicsscene>
#include <Qgraphicsview>
#include <QAbstractButton>
#include "Environnement.h"
#include "ParamSim.h"
#include <QTimer>
#include "TimeLord.h"
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
	

	ParamSim *parameters;
	parameters = new ParamSim();

	Environnement *mMonde;
	mMonde = new Environnement(parameters);

	QGraphicsView* view = new QGraphicsView;
	view->setScene(mMonde->scene());
	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->setStretchFactor(mLeftLayout,3); //Make the left layout occupy 3 times as much space as the right layout.


	//QBrush greenBrush(Qt::green);
	//QBrush blueBrush(Qt::blue);
	//QPen outlinePen(Qt::black);
	//outlinePen.setWidth(2);

	//
	//QGraphicsRectItem *rectangle = scene->addRect(0, 0, 80, 100, outlinePen, blueBrush);
	////scene->addRect(0, 0, 0.5, 0.5);

	
	mLeftLayout->addWidget(view);
	
	//connect(mPlayButton,&QPushButton::released, this, &fooo);


	//Add Buttons to groupbox
	mSimGroupBoxLayout->addWidget(mPlayButton);
	mSimGroupBoxLayout->addWidget(mPauseButton);
	mSimGroupBoxLayout->addWidget(mStepButton);
	mSimGroupBoxLayout->addWidget(mStopButton);




															//Elapsed Tics
	mTicLabel = new QLabel("Elapsed tics: ");
	mTicValueLabel = new QLabel("");

	mTicLayout = new QHBoxLayout;
	mTicLayout->addWidget(mTicLabel);
	mTicLayout->addWidget(mTicValueLabel);

	
	
	
	








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




	//set this layout
	setLayout(mMainLayout);
}

void QSimulationTab::updateTicLabel() {


	mTicValue += 1;
	mTicString->number(mTicValue);
	mTicValueLabel->setText(*mTicString);


}