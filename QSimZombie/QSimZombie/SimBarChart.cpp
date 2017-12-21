#include "SimBarChart.h"



SimBarChart::SimBarChart(QChart * chart, const std::map<QString, int>& data, QString title)
	:QSimChart(chart, title)
{
	mDataSerie = new QBarSeries;
	CreateSerie(data);
}

SimBarChart::SimBarChart(QChart * chart, const std::vector<int>& data, QString title)
	: QSimChart(chart, title)
{
	mDataSerie = new QBarSeries;
	CreateSerie(data);
}

SimBarChart::SimBarChart(const std::map<QString, int>& data, QString title)
	: QSimChart(title)
{
	mDataSerie = new QBarSeries;
	CreateSerie(data);
}

SimBarChart::SimBarChart(const std::vector<int>& data, QString title)
	: QSimChart(title)
{
	mDataSerie = new QBarSeries;
	CreateSerie(data);
}


SimBarChart::~SimBarChart()
{
}

void SimBarChart::CreateChart()
{
	mChart->addSeries(mDataSerie);
	PrepChart(mTitle);
}

void SimBarChart::CreateSerie(std::map<QString, int> data)
{
	QBarSeries * serie = dynamic_cast<QBarSeries * >(mDataSerie);
	QBarSet * set = new QBarSet("Data");
	for (auto & value : data)
	{
		*set << value.second;
	}
	serie->append(set);
}

void SimBarChart::CreateSerie(std::vector<int> data)
{
	QBarSeries * serie = dynamic_cast<QBarSeries * >(mDataSerie);
	QBarSet * set = new QBarSet("Data");
	for (auto & value : data)
	{
		*set << value;
	}
	serie->append(set);
}
