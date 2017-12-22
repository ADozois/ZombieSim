#include "SimPieChart.h"
#include <QPieSeries>
#include "QStatSim.h"



SimPieChart::SimPieChart(QChart * chart, const std::map<QString, int> * data, QString title)
	:QSimChart(chart, title),
	mData{ data }
{
	mDataSerie = new QPieSeries;
	CreateSerie();
}


SimPieChart::SimPieChart(const std::map<QString, int> * data, QString title)
	:QSimChart(title),
	mData{ data }
{
	mDataSerie = new QPieSeries;
	CreateSerie();
}


SimPieChart::~SimPieChart()
{
}

void SimPieChart::CreateChart()
{
	mChart->addSeries(mDataSerie);
	PrepChart(mTitle);
}

void SimPieChart::CreateSerie()
{
	QPieSeries * serie = dynamic_cast<QPieSeries *>(mDataSerie);
	int index{ 0 };
	for (auto & map : *mData)
	{
		serie->append(map.first, map.second);
		serie->slices().at(index)->setLabelVisible();
		index++;
	}
}


void SimPieChart::UpdateGraph() {
	QPieSeries * serie = dynamic_cast<QPieSeries *>(mDataSerie);
	if (serie)
	{
		serie->clear();
		CreateSerie();
	}
}