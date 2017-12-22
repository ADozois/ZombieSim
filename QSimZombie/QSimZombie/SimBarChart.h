#ifndef SIM_BAR_CHART_H
#define SIM_BAR_CHART_H

#include "QSimChart.h"

class SimBarChart :	public QSimChart
{
public:
	SimBarChart() = delete;
	SimBarChart(QChart * chart, const std::map<QString, int> * data, QString title = "");
	SimBarChart(const std::map<QString, int> * data, QString title = "");
	~SimBarChart();
	void CreateChart() override;

public slots:
	void UpdateGraph() override;



protected:
	void CreateSerie() override;
	QStringList CreateBarCategory();
	QStringList mCategory;
	const std::map<QString, int> * mData;
};

#endif // !SIM_BAR_CHART_H

