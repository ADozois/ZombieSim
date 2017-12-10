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

	/* Simulation View goes in mLeftLayout */
	//Add simulation graphic view in this layout!*************************
	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->setStretchFactor(mLeftLayout,3); //Make the left layout occupy 3 times as much space as the right layout.

	//Rest of setup
	mMainLayout->addLayout(mRightLayout);

	//Add Buttons to groupbox
	mSimGroupBoxLayout->addWidget(mPlayButton);
	mSimGroupBoxLayout->addWidget(mPauseButton);
	mSimGroupBoxLayout->addWidget(mStepButton);
	mSimGroupBoxLayout->addWidget(mStopButton);

	//Set a groupbox inner layout
	mSimGroupBox->setLayout(mSimGroupBoxLayout);
	
	//Layout that's on the right for the buttons...
	//mRightLayout->addWidget(mIconLabel); //Icon on the right?
	mRightLayout->addStretch();
	mRightLayout->addLayout(mPushRightLayout);
	mPushRightLayout->addStretch();
	mPushRightLayout->addWidget(mSimGroupBox);




	//set this layout
	setLayout(mMainLayout);
}