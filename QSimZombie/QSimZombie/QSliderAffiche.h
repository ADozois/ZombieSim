#ifndef QSliderAffiche_H
#define QSliderAffiche_H

#include <QSlider>

class QSliderAffiche : public QSlider
{
	Q_OBJECT
public:
	explicit QSliderAffiche(QWidget *parent = 0);
	explicit QSliderAffiche(Qt::Orientation orientation, QWidget *parent = 0);

protected:
	virtual void sliderChange(SliderChange change);
};

#endif // QSliderAffiche_H

