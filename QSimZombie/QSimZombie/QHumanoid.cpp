#include "QHumanoid.h"
#include "ParamSim.h"
#include <QPainter>
#include <random>
#include "Environnement.h"





RandomNorm *QHumanoid::mRunGenerator { nullptr };
RandomNorm *QHumanoid::mWalkGenerator{ nullptr };
RandomNorm *QHumanoid::mRayGenerator { nullptr };
RandomIntUnif *QHumanoid::mNameGenerator { nullptr };
const QList<QString> QHumanoid::mNameList{ "Antoine","Guillaume","Olivier" };
const double QHumanoid::mWalkDev{ 0.1 };
const double QHumanoid::mRayDev{ 0.3 };
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
const qreal QHumanoid::mEatingRange{ pow(static_cast<qreal>(mSizeHumanoid),2) };
//QRectF QHumanoid::mRectF(QPointF(mRectP1, mRectP2), QSizeF(mRectH, mRectW));


QHumanoid::QHumanoid(double x, double y, Environnement *currentEnvironnement, humanoideType typeOfHumanoide, QGraphicsItem *parent)
	: QGraphicsItem(parent),
	mEnergy{ 100 },
	mViewRay{ 0.0 },
	mRotationAngle{ ParamSim::RotationAngle() },
	mWalkSpeed{ 0.0 },
	mRunSpeed{ 0.0 },
	mEnvironnement{ currentEnvironnement },
	mHumanoideType{ typeOfHumanoide },
	mPosition{ x, y },
	mRectF{ QPointF(mRectP1, mRectP2), QSizeF(mRectH, mRectW) },
	mBrushColor{ mHumanoidColor },
	mPenColor{ mContourColor },
	mIsTurning{ false }
{
	mRunGenerator = new RandomNorm(ParamSim::ProbSpeed(), ParamSim::ProbSpeed()*mRayDev);
	mRayGenerator = new RandomNorm(ParamSim::ViewRay(), ParamSim::ViewRay()*mRunDev);
	mWalkGenerator = new RandomNorm(ParamSim::ProbSpeed() + mOffsetRun, (ParamSim::ProbSpeed() + mOffsetRun)*mWalkDev);
	mNameGenerator = new RandomIntUnif(mBeginName, mEndName);
	mWalkSpeed = mWalkGenerator->Generate();
	mRunSpeed = mRunGenerator->Generate();
	mViewRay = mRayGenerator->Generate();
	mViewRaySq = mViewRay*mViewRay;
	mName = mNameList.at(mNameGenerator->Generate());
	mTurningDirection = new QVector2D[mNumberOfTurningDirection];
}

QHumanoid::QHumanoid(double x, double y, Environnement * currentEnvironnemnt, humanoideType typeOfHumanoide, qreal runSpeed, qreal walkSpeed, qreal viewRay, QGraphicsItem * parent)
	: QGraphicsItem(parent),
	mEnergy{ 100 },
	mRotationAngle{ ParamSim::RotationAngle() },
	mEnvironnement{ currentEnvironnemnt },
	mHumanoideType{ typeOfHumanoide },
	mPosition{ x, y },
	mRectF{ QPointF(mRectP1, mRectP2), QSizeF(mRectH, mRectW) },
	mBrushColor{ mHumanoidColor },
	mPenColor{ mContourColor },
	mIsTurning{ false }
{
	mRunGenerator = new RandomNorm(0, runSpeed*mRunDev);
	mRayGenerator = new RandomNorm(0, viewRay*mRunDev);
	mWalkGenerator = new RandomNorm(0, (runSpeed + mOffsetRun)*mWalkDev);
	mNameGenerator = new RandomIntUnif(mBeginName, mEndName);
	mWalkSpeed = runSpeed + mWalkGenerator->Generate();
	mViewRay = viewRay + mRayGenerator->Generate();
	mViewRaySq = mViewRay*mViewRay;
	mRunSpeed = runSpeed + mRunGenerator->Generate();
	mName = mNameList.at(mNameGenerator->Generate());
	mTurningDirection = new QVector2D[mNumberOfTurningDirection];
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

void QHumanoid::advance(int phase, int index)
{

}

void QHumanoid::advance(int phase)
{
	advance(phase, 0);
}

void QHumanoid::ReduceEnergy()
{
	--mEnergy;
	if (mEnergy < 0)
		mEnergy = 0;
}

void QHumanoid::ReduceEnergy(int loss)
{
	mEnergy -= loss;
	if (mEnergy < 0)
		mEnergy = 0;
}

void QHumanoid::AddEnergy()
{
	++mEnergy;
	if (mEnergy > 100)
		mEnergy = 100;
}

void QHumanoid::AddEnergy(int gain)
{
	mEnergy += gain;
	if (mEnergy > 100)
		mEnergy = 100;
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
	return mMovementDirection;
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

