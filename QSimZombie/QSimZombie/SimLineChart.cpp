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
	mChart->addAxis(XAxis, Qt::AlignBottom);
	mChart->addAxis(YAxis, Qt::AlignLeft);
}

void SimLineChart::CreateSerie()
{
	QLineSeries * serie = dynamic_cast<QLineSeries *>(mDataSerie);
	if (serie)
	{
		serie->append(mX, *mData->end());
	}
}


void SimLineChart::UpdateGraph() {
	QStatSim::UpdatePop();
	CreateSerie();
	mX++;
}