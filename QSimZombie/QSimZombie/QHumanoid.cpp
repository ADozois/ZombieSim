#include "QHumanoid.h"
#include <random>

const QList<QString> QHumanoid::mNameList{"Antoine","Guillaume","Olivier"};

QHumanoid::QHumanoid(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, QGraphicsItem *parent)
	: QGraphicsItem(parent),
	mEnergy{ 100 },
	mViewRay{ viewRay },
	mRotationAngle{ rotationAngle },
	mWalkSpeed{ walkSpeed },
	mRunSpeed{ runSpeed },
	mClosestHuman{ nullptr }
{

}

QHumanoid::~QHumanoid()
{
}

QRectF QHumanoid::boundingRect() const
{
	return QRectF();
}

void QHumanoid::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
}
