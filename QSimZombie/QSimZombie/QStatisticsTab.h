#ifndef Q_STATISTICS_TAB_H
#define Q_STATISTICS_TAB_H
#include <QtWidgets/QMainWindow>
#include "QStatisticsTab.h"
#include <QtCharts>
using namespace QtCharts;
#include <QChart>
#include <QChartView>
#include <QHBoxLayout>
#include <QVBoxLayout>
class QStatisticsTab : public QWidget {
	
	Q_OBJECT

public:

	QStatisticsTab(QWidget *parent = Q_NULLPTR);

protected:

	QChart *mChart;
	QChart *mChart2;
	QChart *mChart3;
	QChart *mChart4;

	QChartView *mChartView;
	QChartView *mChartView2;
	QChartView *mChartView3;
	QChartView *mChartView4;

	QLineSeries *mDataSeries;
	QLineSeries *mDataSeries2;
	QLineSeries *mDataSeries3;
	QLineSeries *mDataSeries4;

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


};





#endif //Q_STATISTICS_TAB_H