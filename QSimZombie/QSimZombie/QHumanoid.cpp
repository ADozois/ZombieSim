#include "QHumanoid.h"
#include <random>

RandomNorm *QHumanoid::mRunGenerator {nullptr};
RandomNorm *QHumanoid::mWalkGenerator {nullptr};
RandomIntUnif *QHumanoid::mNameGenerator {nullptr};
const QList<QString> QHumanoid::mNameList{"Antoine","Guillaume","Olivier"};
const double QHumanoid::mWalkDev{0.1};
const double QHumanoid::mRunDev{0.1};
const int QHumanoid::mBeginName{1};
const int QHumanoid::mEndName{3};
const double QHumanoid::mRectP1{5.0};
const double QHumanoid::mRectP2{5.0};
const double QHumanoid::mRectH{10.0};
const double QHumanoid::mRectW{10.0};
const double QHumanoid::mPenWidth{1.0};
QRectF QHumanoid::mRectF(QPointF(mRectP1, mRectP2), QSizeF(mRectH, mRectW));


QHumanoid::QHumanoid(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, QGraphicsItem *parent)
	: QGraphicsItem(parent),
	mEnergy{ 100 },
	mViewRay{ viewRay },
	mRotationAngle{ rotationAngle },
	mWalkSpeed{ 0.0 },
	mRunSpeed{ 0.0 },
	mClosestHuman{ nullptr }
{
	mRunGenerator = new RandomNorm(runSpeed, runSpeed*mRunDev);
	mWalkGenerator = new RandomNorm(walkSpeed, walkSpeed*mWalkDev);
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

