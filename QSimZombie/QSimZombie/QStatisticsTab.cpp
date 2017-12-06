#include "QStatisticsTab.h"



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
	mChart = new QChart;
	mChart2 = new QChart;
	mChart3 = new QChart;
	mChart4 = new QChart;

	//Series
	mDataSeries = new QLineSeries;
	mDataSeries2 = new QLineSeries;
	mDataSeries3 = new QLineSeries;
	mDataSeries4 = new QLineSeries;
	
	//Axis
	mXAxis = new QValueAxis;
	mYAxis = new QValueAxis;

	mXAxis2 = new QValueAxis;
	mYAxis2 = new QValueAxis;

	mXAxis3 = new QValueAxis;
	mYAxis3 = new QValueAxis;

	mXAxis4 = new QValueAxis;
	mYAxis4 = new QValueAxis;


	mChart->addAxis(mXAxis,Qt::AlignBottom);
	mChart->addAxis(mYAxis,Qt::AlignLeft);

	mChart2->addAxis(mXAxis2, Qt::AlignBottom);
	mChart2->addAxis(mYAxis2, Qt::AlignLeft);

	mChart3->addAxis(mXAxis3, Qt::AlignBottom);
	mChart3->addAxis(mYAxis3, Qt::AlignLeft);

	mChart4->addAxis(mXAxis4, Qt::AlignBottom);
	mChart4->addAxis(mYAxis4, Qt::AlignLeft);

	mXAxis->setRange(0, 30);
	mYAxis->setRange(0, 30);

	mXAxis2->setRange(0, 30);
	mYAxis2->setRange(0, 30);

	mXAxis3->setRange(0, 30);
	mYAxis3->setRange(0, 30);

	mXAxis4->setRange(0, 30);
	mYAxis4->setRange(0, 30);

	*mDataSeries << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
	*mDataSeries2 << QPointF(5, 16) << QPointF(19, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
	*mDataSeries3 << QPointF(0, 16) << QPointF(9, 14) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
	*mDataSeries4 << QPointF(10, 10) << QPointF(8, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);

	mChart->addSeries(mDataSeries);
	mChart2->addSeries(mDataSeries2);
	mChart3->addSeries(mDataSeries3);
	mChart4->addSeries(mDataSeries4);

	mChartView = new QChartView(mChart);
	mChartView2 = new QChartView(mChart2);
	mChartView3 = new QChartView(mChart3);
	mChartView4 = new QChartView(mChart4);

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