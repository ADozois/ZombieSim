#include "QSliderAffiche.h"

#include <QStyleOptionSlider>
#include <QToolTip>

QSliderAffiche::QSliderAffiche(QWidget * parent)
	: QSlider(parent)
{
}

QSliderAffiche::QSliderAffiche(Qt::Orientation orientation, QWidget * parent)
	: QSlider(orientation, parent)
{
}

void QSliderAffiche::sliderChange(QAbstractSlider::SliderChange change)
{
	QSlider::sliderChange(change);

	if (change == QAbstractSlider::SliderValueChange)
	{
		QStyleOptionSlider opt;
		initStyleOption(&opt);

		QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
		QPoint bottomRightCorner = sr.bottomLeft();

		QToolTip::showText(mapToGlobal(QPoint(bottomRightCorner.x(), bottomRightCorner.y())), QString::number(value()), this);
	}
}