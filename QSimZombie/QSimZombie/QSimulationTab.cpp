#include "QSimulationTab.h"

#include <Qgraphicsscene>
#include <Qgraphicsview>

#include "Environnement.h"
#include "ParamSim.h"

QSimulationTab::QSimulationTab(QWidget *parent)
	: QWidget(parent)
{
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
	
	//Setup
	mSimGroupBox->setLayout(mSimGroupBoxLayout);
	
	//Buttons
	mSimGroupBoxLayout->addWidget(mPlayButton);
	mSimGroupBoxLayout->addWidget(mPauseButton);
	mSimGroupBoxLayout->addWidget(mStepButton);
	mSimGroupBoxLayout->addWidget(mStopButton);


	/* Simulation View goes in mLeftLayout */
	//Add simulation graphic view in this layout!*************************
	
	ParamSim *parameters;
	parameters = new ParamSim();
	Environnement *mMonde;
	mMonde = new Environnement(parameters);

	QGraphicsView* view = new QGraphicsView;
	view->setScene(mMonde->scene());


	//QBrush greenBrush(Qt::green);
	//QBrush blueBrush(Qt::blue);
	//QPen outlinePen(Qt::black);
	//outlinePen.setWidth(2);

	//
	//QGraphicsRectItem *rectangle = scene->addRect(0, 0, 80, 100, outlinePen, blueBrush);
	////scene->addRect(0, 0, 0.5, 0.5);

	
	mLeftLayout->addWidget(view);
	

	//mRightLayout->addWidget(mIconLabel); //Icon on the right?

	mPushRightLayout->addStretch();
	mPushRightLayout->addWidget(mSimGroupBox);

	mRightLayout->addLayout(mPushRightLayout);
	mRightLayout->addStretch();
	
	

	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->addLayout(mRightLayout);



	setLayout(mMainLayout);
}