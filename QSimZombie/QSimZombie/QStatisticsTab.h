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


using namespace QtCharts;


class QStatisticsTab : public QWidget {
	
	Q_OBJECT

public:

	QStatisticsTab(QWidget *parent = Q_NULLPTR);


private:
	void CreatePieChartSerie(std::map<QString, int> data, QPieSeries* serie);
	void CreatePieChart(std::map<QString, int> data, QChart * chart, QPieSeries* serie, QString title);
	void CreateBarChartSerie(std::map<QString, int> data, QBarSeries * serie);
	QStringList CreateBarCategory(std::map<QString, int> data);
	void CreateBarChart(std::map<QString, int> data, QChart * chart, QBarSeries* serie, QString title);
	void PrepChart(QChart * chart, QString title);

protected:

	QChart *mChart;
	QChart *mChart2;
	SimBarChart *mChart3;
	SimPieChart *mChart4;

	QChartView *mChartView;
	QChartView *mChartView2;
	QChartView *mChartView3;
	QChartView *mChartView4;

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