#include "SimBarChart.h"
#include "QStatSim.h"


SimBarChart::SimBarChart(QChart * chart, const std::map<QString, int> * data, QString title)
	:QSimChart(chart, title),
	mData{ data }
{
	mDataSerie = new QBarSeries;
	CreateSerie();
	mCategory = CreateBarCategory();
}


SimBarChart::SimBarChart(const std::map<QString, int> * data, QString title)
	: QSimChart(title),
	mData{ data }
{
	mDataSerie = new QBarSeries;
	CreateSerie();
	mCategory = CreateBarCategory();
}


SimBarChart::~SimBarChart()
{
}

void SimBarChart::CreateChart()
{
	QBarCategoryAxis *axis = new QBarCategoryAxis();
	mChart->addSeries(mDataSerie);
	PrepChart(mTitle);
	axis->append(mCategory);
	mChart->createDefaultAxes();
	mChart->setAxisX(axis, mDataSerie);
}

void SimBarChart::CreateSerie()
{
	QBarSeries * serie = dynamic_cast<QBarSeries * >(mDataSerie);
	QBarSet * set = new QBarSet("Data");
	if (serie)
	{
		for (auto & value : *mData)
		{
			*set << value.second;
		}
		serie->append(set);
	}
}


QStringList SimBarChart::CreateBarCategory()
{
	QStringList category;
	for (auto & value : *mData)
	{
		category << value.first;
	}
	return category;
}

void SimBarChart::UpdateGraph() {
	QBarSeries * serie = dynamic_cast<QBarSeries * >(mDataSerie);
	if (serie) {
		serie->clear();
		CreateSerie();
	}
}