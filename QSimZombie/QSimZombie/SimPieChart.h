#ifndef SIM_PIE_CHART_H
#define SIM_PIE_CHART_H

#include "QSimChart.h"
class SimPieChart : public QSimChart
{
public:
	SimPieChart() = delete;
	SimPieChart(QChart * chart, const std::map<QString, int> * data, QString title = "");
	SimPieChart(const std::map<QString, int> * data, QString title = "");
	~SimPieChart();
	void CreateChart() override;

public slots:
	void UpdateGraph() override;
	

protected:
	void CreateSerie() override;
	const std::map<QString, int> * mData;
};

#endif // !SIM_PIE_CHART_H





