#include "QSimZombie.h"
#include <iostream>
QSimZombie::QSimZombie(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Program Icon
	setWindowIcon(QIcon(":/QSimZombie/Icon"));
	setWindowTitle("QSimZombie");

	mSimTab = new QSimulationTab;
	mStatTab = new QStatisticsTab;
	mParamTab = new QParametersTab;
	mLord = new TimeLord;

	QPushButton* mPlay = mSimTab->getPlayButton();
	QPushButton* mStop = mSimTab->getStopButton();
	QPushButton * mStep = mSimTab->getStepButton();
	QPushButton * mPause = mSimTab->getPauseButton();
	QPushButton* mValidate = mParamTab->getValidateButton();

<<<<<<< HEAD
=======
	connect(mValidate, &QPushButton::clicked, mParamTab, &QParametersTab::updateParameters);
	connect(mValidate, &QPushButton::clicked, this, &QSimZombie::setupSim);
	connect(mValidate, &QPushButton::clicked, mSimTab, &QSimulationTab::activateStart);
	connect(mPlay, &QPushButton::clicked, this, &QSimZombie::disableParametersTab);
	connect(mPlay, &QPushButton::clicked, this, &QSimZombie::disableStatTab);
	connect(mStop, &QPushButton::clicked, this, &QSimZombie::activateParametersTab);
>>>>>>> master

<<<<<<< HEAD
	connect(mValidate, &QPushButton::clicked, this, &QSimZombie::disableParametersTab);
	connect(mPlay,&QPushButton::clicked,this, &QSimZombie::disableParametersTab);
=======
	
>>>>>>> GCN_dev

	connect(mStop,&QPushButton::clicked, this, &QSimZombie::activateParametersTab);

<<<<<<< HEAD

=======
>>>>>>> master
	mTabWidget = new QTabWidget;
	mSplitter = new QSplitter;
	mSplitter->addWidget(mTabWidget);

<<<<<<< HEAD
	mTabWidget->insertTab(mSimTabIndex, mSimTab, "Simulation") ;
	mTabWidget->insertTab(mStatTabIndex, mStatTab, "Statistics") ;
	mTabWidget->insertTab(mParamTabIndex, mParamTab, "Parameters") ;

	setCentralWidget(mSplitter);
}
=======
	mTabWidget->insertTab(mSimTabIndex, mSimTab, "Simulation");
	mTabWidget->insertTab(mStatTabIndex, mStatTab, "Statistics");
	mTabWidget->insertTab(mParamTabIndex, mParamTab, "Parameters");
	disableStatTab();



	//Timer connection and all that jaz
	//Connection for buttons
	connect(mLord->Timer(), &QTimer::timeout, mSimTab, &QSimulationTab::updateTicLabel);
	
	connect(mPlay, &QPushButton::clicked, mLord, &TimeLord::run);

	connect(mPlay, &QPushButton::clicked, mStep, &QPushButton::setEnabled);
	connect(mPlay, &QPushButton::clicked, mPause, &QPushButton::setDisabled);
	connect(mPlay, &QPushButton::clicked, mStop, &QPushButton::setDisabled);

	connect(mPause, &QPushButton::clicked, mLord, &TimeLord::pause);
	connect(mPause, &QPushButton::clicked, mStep, &QPushButton::setDisabled);

	connect(mStep, &QPushButton::clicked, mLord, &TimeLord::step);

	connect(mStop, &QPushButton::clicked, mLord, &TimeLord::stop);
	connect(mStop, &QPushButton::clicked, mPlay, &QPushButton::setEnabled);
	connect(mStop, &QPushButton::clicked, mStep, &QPushButton::setEnabled);
	connect(mStop, &QPushButton::clicked, mPause, &QPushButton::setEnabled);


	setCentralWidget(mSplitter);
}

>>>>>>> master



void QSimZombie::activateParametersTab() {

void QSimZombie::activateParametersTab() {

	mTabWidget->setTabEnabled(mParamTabIndex, true);

	mTabWidget->setTabEnabled(mParamTabIndex,true);

}

void QSimZombie::disableParametersTab() {


	mTabWidget->setCurrentIndex(mSimTabIndex);
<<<<<<< HEAD
	mTabWidget->setTabEnabled(mParamTabIndex,false);


=======
	mTabWidget->setTabEnabled(mParamTabIndex, false);


}

void QSimZombie::activateStatTab() {
	mTabWidget->setTabEnabled(mStatTabIndex, true);
}

void QSimZombie::disableStatTab() {
	mTabWidget->setTabEnabled(mStatTabIndex, false);
}

void QSimZombie::setupSimTab()
{
	mSimTab->setWorld(mLord->Monde());
}

void QSimZombie::setupSim() {
	mLord->createWorld();
	setupSimTab();
>>>>>>> master
}