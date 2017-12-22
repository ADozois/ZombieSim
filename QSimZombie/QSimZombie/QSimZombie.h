#ifndef Q_SIM_ZOMBIE_H
#define Q_SIM_ZOMBIE_H

#include "QSimulationTab.h"//Tabs: Simulation, Statistics, Parameters.
#include "QStatisticsTab.h"
#include "QParametersTab.h"

#include <QtWidgets/QMainWindow>
#include "ui_QSimZombie.h"


#include <QMenuBar>//QWidgets
#include <QLayout>
#include <QLabel>
#include <QTabWidget>
#include <QSplitter>





class QSimZombie : public QMainWindow
{
	Q_OBJECT

public:
	QSimZombie(QWidget *parent = Q_NULLPTR);

	public slots:


	void activateParametersTab();
	void disableParametersTab();

private:
	Ui::QSimZombieClass ui;
	QMenuBar *mMenuBar;
	QLayout *mMainLayout;
	QLabel *mLabel;
	QTabWidget *mTabWidget;
	QSplitter *mSplitter;
	QSimulationTab *mSimTab;
	QStatisticsTab *mStatTab;
	QParametersTab *mParamTab;

	int mSimTabIndex{ 0 };
	int mStatTabIndex{ 1 };
	int mParamTabIndex{ 2 };
};
#endif //Q_SIM_ZOMBIE_H	