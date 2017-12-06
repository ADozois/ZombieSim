#include "QSimulationTab.h"

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
	mMainLayout->addLayout(mLeftLayout);


	//Rest of setup
	mMainLayout->addLayout(mRightLayout);

	//mRightLayout->addWidget(mIconLabel); //Icon on the right?

	mRightLayout->addStretch();
	mRightLayout->addLayout(mPushRightLayout);
	mPushRightLayout->addStretch();
	mPushRightLayout->addWidget(mSimGroupBox);



	setLayout(mMainLayout);
}