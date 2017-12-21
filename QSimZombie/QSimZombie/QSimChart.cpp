#include "QSimChart.h"

QSimChart::QSimChart(QChart * chart, QString title, QWidget *parent)
	:QWidget(parent),
	mChart{ chart },
	mTitle{ title },
	mDataSerie{ nullptr },
	mLegendVisible{ false }
{
}

QSimChart::QSimChart(QString title, QWidget *parent)
	:QWidget(parent),
	mTitle{ title },
	mDataSerie{ nullptr },
	mLegendVisible{ false } 
{
	mChart = new QChart;
}

	
QSimChart::~QSimChart()
{
}

void QSimChart::SetTitle(QString title)
{
	mTitle = title;
}

void QSimChart::PrepChart(QString title)
{
	mChart->setTitle(title);
	if (!mLegendVisible)
	{
		mChart->legend()->hide();
	}
}

QChart * QSimChart::Chart() {
	return mChart;
}

