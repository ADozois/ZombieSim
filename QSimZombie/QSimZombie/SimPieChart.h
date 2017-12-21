#ifndef SIM_PIE_CHART_H
#define SIM_PIE_CHART_H

#include "QSimChart.h"
class SimPieChart : public QSimChart
{
public:
	SimPieChart() = delete;
	SimPieChart(QChart * chart, const std::map<QString, int> & data, QString title = "");
	SimPieChart(QChart * chart, const std::vector<int> & data, QString title = "");
	SimPieChart(const std::map<QString, int> & data, QString title = "");
	SimPieChart(const std::vector<int> & data, QString title = "");
	~SimPieChart();
	void CreateChart() override;


protected:
	void CreateSerie(std::map<QString, int> data) override;
	void CreateSerie(std::vector<int> data) override;


};

#endif // !SIM_PIE_CHART_H





