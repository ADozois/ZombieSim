#ifndef Q_SIM_CHART_H
#define Q_SIM_CHART_H

#include <QWidget>

#include <QtCharts>
#include <QChart>
#include <QChartView>
#include <QAbstractSeries>


using namespace QtCharts;

class QSimChart : public QWidget
{
	Q_OBJECT

public:
	QSimChart() = delete;
	QSimChart(QChart * chart, QString title = "", QWidget *parent = nullptr);
	QSimChart(QString title = "", QWidget *parent = nullptr);
	virtual ~QSimChart();
	void SetTitle(QString title);
	virtual void CreateChart() = 0;
	QChart * Chart();

public slots:
	virtual void UpdateGraph() = 0;
	
protected:
	virtual void CreateSerie() = 0;
	void PrepChart(QString title);


	QChart * mChart;
	QAbstractSeries * mDataSerie;
	QString mTitle;
	bool mLegendVisible;
};

#endif // !Q_SIM_CHART_H

