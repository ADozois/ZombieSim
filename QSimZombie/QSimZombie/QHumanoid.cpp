#include "QHumanoid.h"
#include "ParamSim.h"
#include <QPainter>
#include <random>

RandomNorm *QHumanoid::mRunGenerator { nullptr };
RandomNorm *QHumanoid::mWalkGenerator { nullptr };
RandomIntUnif *QHumanoid::mNameGenerator { nullptr };
const QList<QString> QHumanoid::mNameList{ "Antoine","Guillaume","Olivier" };
const double QHumanoid::mWalkDev{ 0.1 };
const double QHumanoid::mOffsetRun{ 5 };
const double QHumanoid::mRunDev{ 0.1 };
const int QHumanoid::mBeginName{ 0 };
const int QHumanoid::mEndName{ 2 };
const double QHumanoid::mRectP1{ 5.0 };
const double QHumanoid::mRectP2{ 5.0 };
const double QHumanoid::mRectH{ 10.0 };
const double QHumanoid::mRectW{ 10.0 };
const double QHumanoid::mPenWidth{ 2.0 };
const QColor QHumanoid::mHumanoidColor{ Qt::black };
const QColor QHumanoid::mContourColor{ Qt::black };
const int QHumanoid::mSizeHumanoid{ 10 };
const double QHumanoid::mOpacityHumanoid{ 0.60 };
//QRectF QHumanoid::mRectF(QPointF(mRectP1, mRectP2), QSizeF(mRectH, mRectW));


QHumanoid::QHumanoid(double x, double y, QGraphicsItem *parent)
	: QGraphicsItem(parent),
	mEnergy{ 100 },
	mViewRay{ ParamSim::ViewRay() },
	mRotationAngle{ ParamSim::RotationAngle() },
	mWalkSpeed{ 0.0 },
	mRunSpeed{ 0.0 },
	mClosestHuman{ nullptr },
	mPosition{x, y},
	mRectF(QPointF(mRectP1, mRectP2), QSizeF(mRectH, mRectW)),
	mBrushColor{mHumanoidColor},
	mPenColor{mContourColor}
{
	mRunGenerator = new RandomNorm(ParamSim::ProbSpeed(), ParamSim::ProbSpeed()*mRunDev);
	mWalkGenerator = new RandomNorm(ParamSim::ProbSpeed() + mOffsetRun, (ParamSim::ProbSpeed() + mOffsetRun)*mWalkDev);
	mNameGenerator = new RandomIntUnif(mBeginName, mEndName);
	mWalkSpeed = mWalkGenerator->Generate();
	mRunSpeed = mRunGenerator->Generate();
	mName = mNameList.at(mNameGenerator->Generate());
}

QHumanoid::~QHumanoid()
{
}

QRectF QHumanoid::boundingRect() const
{
	return mRectF;
}

void QHumanoid::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	InitializeVisual(painter);
}

void QHumanoid::advance(int phase)
{
}

void QHumanoid::ReduceEnergy()
{
	--mEnergy;
}

void QHumanoid::ReduceEnergy(int loss)
{
	mEnergy -= loss;
}

void QHumanoid::AddEnergy()
{
	++mEnergy;
}

void QHumanoid::AddEnergy(int gain)
{
	mEnergy += gain;
}

int QHumanoid::Energy()
{
	return mEnergy;
}

qreal QHumanoid::ViewRay()
{
	return mViewRay;
}

qreal QHumanoid::RunSpeed()
{
	return mRunSpeed;
}

qreal QHumanoid::WalkSpeed()
{
	return mWalkSpeed;
}

QString QHumanoid::Name()
{
	return mName;
}

qreal QHumanoid::RotationAngle()
{
	return mRotationAngle;
}

QVector2D QHumanoid::MouvementDirection()
{
	return mMouvementDirection;
}

QVector2D QHumanoid::Position()
{
	return mPosition;
}

void QHumanoid::InitializeVisual(QPainter * painter)
{
	QPen pen(Qt::FlatCap);
	pen.setWidth(mPenWidth);
	pen.setColor(mPenColor);
	painter->setPen(pen);
	painter->setOpacity(mOpacityHumanoid);
	painter->setBrush(mBrushColor);
	painter->drawEllipse(mPosition.x(), mPosition.y(), mSizeHumanoid, mSizeHumanoid);
}

