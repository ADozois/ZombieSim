#include "SimPieChart.h"
#include <QPieSeries>


SimPieChart::SimPieChart(QChart * chart, const std::map<QString, int>& data, QString title)
	:QSimChart(chart, title)
{
	mDataSerie = new QPieSeries;
	CreateSerie(data);
}

SimPieChart::SimPieChart(QChart * chart, const std::vector<int>& data, QString title)
	: QSimChart(chart, title)
{
	mDataSerie = new QPieSeries;
	CreateSerie(data);
}

SimPieChart::SimPieChart(const std::map<QString, int>& data, QString title)
	:QSimChart(title)
{
	mDataSerie = new QPieSeries;
	CreateSerie(data);
}

SimPieChart::SimPieChart(const std::vector<int>& data, QString title)
	: QSimChart(title)
{
	mDataSerie = new QPieSeries;
	CreateSerie(data);
}

SimPieChart::~SimPieChart()
{
}

void SimPieChart::CreateChart()
{
	mChart->addSeries(mDataSerie);
	PrepChart(mTitle);
}

void SimPieChart::CreateSerie(std::map<QString, int> data)
{
	QPieSeries * serie = dynamic_cast<QPieSeries *>(mDataSerie);
	int index{ 0 };
	for (auto & map : data)
	{
		serie->append(map.first, map.second);
		serie->slices().at(index)->setLabelVisible();
		index++;
	}
}

void SimPieChart::CreateSerie(std::vector<int> data)
{
	QPieSeries * serie = dynamic_cast<QPieSeries *>(mDataSerie);
	int index{ 0 };
	int sum{ 0 };
	std::for_each(data.begin(), data.end(), [&](int n) { sum += n; });
	for (auto & vect : data)
	{
		serie->append(QString::number(vect/sum), vect);
		index++;
	}
}
