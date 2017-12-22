#ifndef Q_STATISTICS_TAB_H
#define Q_STATISTICS_TAB_H

#include <QtWidgets/QMainWindow>
#include "QStatisticsTab.h"
#include <QtCharts>
#include <QChart>
#include <QChartView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QStatSim.h"
#include "SimPieChart.h"
#include "SimBarChart.h"
#include "SimLineChart.h"


using namespace QtCharts;


class QStatisticsTab : public QWidget {
	
	Q_OBJECT

public:

	QStatisticsTab(QWidget *parent = Q_NULLPTR);


protected:

	SimLineChart *mChartNbrZombie;
	SimLineChart *mChartPopulation;
	SimBarChart *mChartInstance;
	SimPieChart *mChartNames;

	QChartView *mChartViewZombie;
	QChartView *mChartViewPop;
	QChartView *mChartViewInstance;
	QChartView *mChartViewNames;

	QLineSeries *mDataSeries;
	QLineSeries *mDataSeries2;
	QBarSeries *mDataSeries3;
	QPieSeries *mDataSeries4;

	QValueAxis *mXAxis, *mXAxis2, *mXAxis3, *mXAxis4;
	QValueAxis *mYAxis, *mYAxis2, *mYAxis3, *mYAxis4;

	qreal *mMinX, *mMaxX, *mMinY, *mMaxY;

	QHBoxLayout *mMainLayout;
	QVBoxLayout *mLeftLayout;
	QVBoxLayout *mRightLayout;
	QHBoxLayout *mTopRightLayout;
	QHBoxLayout *mTopLeftLayout;
	QHBoxLayout *mDownRightLayout;
	QHBoxLayout *mDownLeftLayout;

	QStatSim mSimStat;


};





#endif //Q_STATISTICS_TAB_H