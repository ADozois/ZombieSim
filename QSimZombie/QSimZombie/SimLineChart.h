#ifndef SIM_LINE_CHART_H
#define SIM_LINE_CHART_H

#include "QSimChart.h"
class SimLineChart :
	public QSimChart
{
public:
	SimLineChart() = delete;
	SimLineChart(QChart * chart, const std::vector<int> * data, QString title = "");
	SimLineChart(const std::vector<int> * data, QString title = "");
	~SimLineChart();
	void CreateChart() override;

public slots:
	void UpdateGraph() override;


private:
	void CreateSerie() override;
	const std::vector<int> * mData;
	int mX;
};

#endif SIM_LINE_CHART_H
