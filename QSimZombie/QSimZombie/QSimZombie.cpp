#include "QSimZombie.h"

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

	mSplitter = new QSplitter;

	mTabWidget = new QTabWidget;
	mTabWidget->addTab(mSimTab, "Simulation");
	mTabWidget->addTab(mStatTab, "Statistics");
	mTabWidget->addTab(mParamTab, "Parameters");


	mSplitter->addWidget(mTabWidget);
	setCentralWidget(mSplitter);






}
