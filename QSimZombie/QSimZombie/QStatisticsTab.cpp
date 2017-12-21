#include "QStatisticsTab.h"
#include "SimPieChart.h"



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
	mChart = new QChart();
	mChart2 = new QChart();
	mChart3 = new QChart();
	mChart4 = new SimPieChart(mSimStat.NbrNomVivant(),"Proportion du nombre d'humain selon leur nom");
	mChart4->CreateChart();

	//Series
	mDataSeries = new QLineSeries;
	mDataSeries2 = new QLineSeries;
	mDataSeries3 = new QBarSeries;
	mDataSeries4 = new QPieSeries;
	
	//Axis
	mXAxis = new QValueAxis;
	mYAxis = new QValueAxis;

	mXAxis2 = new QValueAxis;
	mYAxis2 = new QValueAxis;

	mXAxis3 = new QValueAxis;
	mYAxis3 = new QValueAxis;
	

	mChart->addAxis(mXAxis,Qt::AlignBottom);
	mChart->addAxis(mYAxis,Qt::AlignLeft);

	mChart2->addAxis(mXAxis2, Qt::AlignBottom);
	mChart2->addAxis(mYAxis2, Qt::AlignLeft);

	mChart3->addAxis(mXAxis3, Qt::AlignBottom);
	mChart3->addAxis(mYAxis3, Qt::AlignLeft);


	mXAxis->setRange(0, 30);
	mYAxis->setRange(0, 30);

	mXAxis2->setRange(0, 30);
	mYAxis2->setRange(0, 30);

	mXAxis3->setRange(0, 30);
	mYAxis3->setRange(0, 30);


	*mDataSeries << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
	*mDataSeries2 << QPointF(5, 16) << QPointF(19, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
	CreateBarChart(mSimStat.NbrNomVivant(), mChart3, mDataSeries3, "ttt");
	//CreatePieChart(mSimStat.NbrNomVivant(), mChart4, mDataSeries4, "Proportion du nombre d'humain selon leur nom");

	mChart->addSeries(mDataSeries);
	mChart2->addSeries(mDataSeries2);
	mChart3->addSeries(mDataSeries3);

	mChartView = new QChartView(mChart);
	mChartView2 = new QChartView(mChart2);
	mChartView3 = new QChartView(mChart3);
	mChartView4 = new QChartView(mChart4->Chart());

	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->addLayout(mRightLayout);



	//mLeftLayout->addWidget(mChartView);
	

	mLeftLayout->addLayout(mTopLeftLayout);
	mLeftLayout->addLayout(mDownLeftLayout);
	mRightLayout->addLayout(mTopRightLayout);
	mRightLayout->addLayout(mDownRightLayout);

	mTopLeftLayout->addWidget(mChartView);
	mDownLeftLayout->addWidget(mChartView3);
	mTopRightLayout->addWidget(mChartView2);
	mDownRightLayout->addWidget(mChartView4);
	
	
	setLayout(mMainLayout);
}

void QStatisticsTab::CreatePieChartSerie(std::map<QString, int> data, QPieSeries*  serie)
{
	int index{ 0 };
	for (auto & map : data)
	{
		serie->append(map.first, map.second);
		serie->slices().at(index)->setLabelVisible();
		index++;
	}
}

void QStatisticsTab::CreatePieChart(std::map<QString, int> data, QChart * chart, QPieSeries* serie, QString title)
{
	CreatePieChartSerie(data, serie);
	chart->addSeries(serie);
	PrepChart(chart, title);
}

void QStatisticsTab::CreateBarChartSerie(std::map<QString, int> data, QBarSeries * serie)
{
	QBarSet * set = new QBarSet("Data");
	for (auto & value: data)
	{
		*set << value.second;
	}
	serie->append(set);
}

QStringList QStatisticsTab::CreateBarCategory(std::map<QString, int> data)
{
	QStringList category;
	for (auto & value : data)
	{
		category << value.first;
	}
	return category;
}

void QStatisticsTab::CreateBarChart(std::map<QString, int> data, QChart * chart, QBarSeries * serie, QString title)
{
	QBarCategoryAxis *axis = new QBarCategoryAxis();
	CreateBarChartSerie(data, serie);
	chart->addSeries(serie);
	PrepChart(chart, title);
	axis->append(CreateBarCategory(data));
	chart->createDefaultAxes();
	chart->setAxisX(axis, serie);
}

void QStatisticsTab::PrepChart(QChart * chart, QString title)
{
	chart->setTitle(title);
	chart->legend()->hide();
}
