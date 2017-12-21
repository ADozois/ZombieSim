#ifndef SIM_BAR_CHART_H
#define SIM_BAR_CHART_H

#include "QSimChart.h"

class SimBarChart :	public QSimChart
{
public:
	SimBarChart() = delete;
	SimBarChart(QChart * chart, const std::map<QString, int> & data, QString title = "");
	SimBarChart(QChart * chart, const std::vector<int> & data, QString title = "");
	SimBarChart(const std::map<QString, int> & data, QString title = "");
	SimBarChart(const std::vector<int> & data, QString title = "");
	~SimBarChart();
	void CreateChart() override;


protected:
	void CreateSerie(std::map<QString, int> data) override;
	void CreateSerie(std::vector<int> data) override;
};

#endif // !SIM_BAR_CHART_H

