#include "SimLineChart.h"
#include <QLineSeries>
#include "QStatSim.h"


SimLineChart::SimLineChart(QChart * chart, const std::vector<int> * data, QString title)
	: QSimChart(chart, title),
	mX{ 0 },
	mData{ data }
{
	mDataSerie = new QLineSeries;
	CreateSerie();
}


SimLineChart::SimLineChart(const std::vector<int> * data, QString title)
	: QSimChart(title),
	mX{ 0 },
	mData{ data }
{
	mDataSerie = new QLineSeries;
	CreateSerie();
}


SimLineChart::~SimLineChart()
{
}

void SimLineChart::CreateChart()
{
	QValueAxis * XAxis = new QValueAxis;
	QValueAxis * YAxis = new QValueAxis;
	XAxis->setRange(0, mData->size());
	YAxis->setRange(0, *std::max_element(mData->begin(), mData->end()));
	mChart->addAxis(XAxis, Qt::AlignBottom);
	mChart->addAxis(YAxis, Qt::AlignLeft);
}

void SimLineChart::CreateSerie()
{
	QLineSeries * serie = dynamic_cast<QLineSeries *>(mDataSerie);
	if (serie)
	{
		int index{ 0 };
		for (const auto & value: *mData)
		{
			serie->append(index, value);
			index++;
		}
		mX = index;
		mChart->addSeries(mDataSerie);
	}
}


void SimLineChart::UpdateGraph() {
	QStatSim::UpdatePop();
	CreateSerie();
	mX++;
}