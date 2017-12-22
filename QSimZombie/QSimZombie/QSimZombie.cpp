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

	QPushButton* mPlay = mSimTab->getPlayButton();
	QPushButton* mStop = mSimTab->getStopButton();
	QPushButton* mValidate = mParamTab->getValidateButton();


	connect(mValidate, &QPushButton::clicked, this, &QSimZombie::disableParametersTab);
	connect(mPlay, &QPushButton::clicked, this, &QSimZombie::disableParametersTab);

	connect(mStop, &QPushButton::clicked, this, &QSimZombie::activateParametersTab);


	mTabWidget = new QTabWidget;
	mSplitter = new QSplitter;
	mSplitter->addWidget(mTabWidget);

	mTabWidget->insertTab(mSimTabIndex, mSimTab, "Simulation");
	mTabWidget->insertTab(mStatTabIndex, mStatTab, "Statistics");
	mTabWidget->insertTab(mParamTabIndex, mParamTab, "Parameters");

	setCentralWidget(mSplitter);
}




void QSimZombie::activateParametersTab() {


	mTabWidget->setTabEnabled(mParamTabIndex, true);

}

void QSimZombie::disableParametersTab() {


	mTabWidget->setCurrentIndex(mSimTabIndex);
	mTabWidget->setTabEnabled(mParamTabIndex, false);


}