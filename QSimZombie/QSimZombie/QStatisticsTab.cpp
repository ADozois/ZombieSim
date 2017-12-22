#include "QStatisticsTab.h"
#include "SimPieChart.h"
#include "SimBarChart.h"



QStatisticsTab::QStatisticsTab(QWidget *parent)
	: QWidget(parent)
{
	mMainLayout = new QHBoxLayout;
	mLeftLayout = new QVBoxLayout;
	mRightLayout = new QVBoxLayout;
	mTopLeftLayout = new QHBoxLayout;
	mTopRightLayout = new QHBoxLayout;
	mDownLeftLayout = new QHBoxLayout;
	mDownRightLayout = new QHBoxLayout;


	//Charts
	mChartNbrZombie = new SimLineChart(QStatSim::ZombieEvol(), "Évolution des zombies dans les temps");
	mChartPopulation = new SimLineChart(QStatSim::PopEvol(), "Évolution des humains dans les temps");
	mChartInstance = new SimBarChart(QStatSim::NbrInstance(), "Nombre d'entité par categorie");
	mChartNames = new SimPieChart(mSimStat.NbrNomVivant(), "Proportion du nombre d'humain selon leur nom");

	mChartNbrZombie->CreateChart();
	mChartPopulation->CreateChart();
	mChartInstance->CreateChart();
	mChartNames->CreateChart();


	mChartViewZombie = new QChartView(mChartNbrZombie->Chart());
	mChartViewPop = new QChartView(mChartPopulation->Chart());
	mChartViewInstance = new QChartView(mChartInstance->Chart());
	mChartViewNames = new QChartView(mChartNames->Chart());

	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->addLayout(mRightLayout);



	//mLeftLayout->addWidget(mChartView);


	mLeftLayout->addLayout(mTopLeftLayout);
	mLeftLayout->addLayout(mDownLeftLayout);
	mRightLayout->addLayout(mTopRightLayout);
	mRightLayout->addLayout(mDownRightLayout);

	mTopLeftLayout->addWidget(mChartViewZombie);
	mDownLeftLayout->addWidget(mChartViewInstance);
	mTopRightLayout->addWidget(mChartViewPop);
	mDownRightLayout->addWidget(mChartViewNames);


	setLayout(mMainLayout);
}




