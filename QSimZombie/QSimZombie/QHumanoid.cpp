#include "QHumanoid.h"
#include "ParamSim.h"
#include <QPainter>
#include <random>
#include "Environnement.h"






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
const int QHumanoid::mSizeHumanoid{ 5 };
const double QHumanoid::mOpacityHumanoid{ 0.60 };
const qreal QHumanoid::mEatingRange{ pow(static_cast<qreal>(mSizeHumanoid),2) };


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

	mRunSpeed = abs(RandomNorm::Generate(ParamSim::ProbSpeed() + mOffsetRun, (ParamSim::ProbSpeed() + mOffsetRun)*mRayDev));
	mViewRay = abs(RandomNorm::Generate(ParamSim::ViewRay(), ParamSim::ViewRay()*mRunDev));
	mWalkSpeed = abs(RandomNorm::Generate(ParamSim::ProbSpeed(), ParamSim::ProbSpeed()*mWalkDev));
	mViewRaySq = mViewRay*mViewRay;
	mName = mNameList.at(RandomIntUnif::Generate(mBeginName, mEndName));

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
	mWalkSpeed = walkSpeed + RandomNorm::Generate(0, walkSpeed*mWalkDev);
	mViewRay = viewRay + RandomNorm::Generate(0, viewRay*mWalkDev);
	mViewRaySq = mViewRay*mViewRay;
	mRunSpeed = runSpeed + RandomNorm::Generate(0, runSpeed*mWalkDev);

	mName = mNameList.at(RandomIntUnif::Generate(mBeginName, mEndName));
	mTurningDirection = new QVector2D[mNumberOfTurningDirection];
}

QHumanoid::~QHumanoid()
{
	delete mTurningDirection;
	mTurningDirection = nullptr;
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
	pen.setColor(Qt::black);
	painter->setPen(pen);
	painter->setOpacity(0.05);
	painter->setBrush(Qt::black);
	painter->drawEllipse(QPointF(mPosition.x(), mPosition.y()), ParamSim::ViewRay(), ParamSim::ViewRay());
	pen.setColor(mPenColor);
	painter->setPen(pen);
	painter->setOpacity(mOpacityHumanoid);
	painter->setBrush(mBrushColor);
	painter->drawEllipse(QPointF(mPosition.x(), mPosition.y()), mSizeHumanoid, mSizeHumanoid);
}


void QHumanoid::makeTurn()
{
	mMovementDirection = mTurningDirection[mTurningAtPosition];
	++mTurningAtPosition;
	moveInDirection(movementSpeed::run,1);
	if (mTurningAtPosition > mNumberOfTurningDirection)
	{
		mIsTurning = false;
	}

}

void QHumanoid::moveInDirection(movementSpeed movementSpeed,int const densityModifier)
{
	if (movementSpeed == movementSpeed::run)
	{
		if (mEnergy)
		{
			//int densityModifier = mEnvironnement->getHumainDensity();
			QPointF newPosition(pos().x() + mMovementDirection.x()*(mRunSpeed/ densityModifier), pos().y() + mMovementDirection.y()*(mRunSpeed/ densityModifier));
			checkForWalls(newPosition, mRunSpeed);
			this->setPos(newPosition);
			ReduceEnergy();
		}
		else
		{
			QPointF newPosition(pos().x() + mMovementDirection.x()*(mWalkSpeed/ densityModifier), pos().y() + mMovementDirection.y()*mWalkSpeed/ densityModifier);
			checkForWalls(newPosition, mWalkSpeed);
			this->setPos(newPosition);
		}
	}
	else {
		QPointF newPosition(pos().x() + mMovementDirection.x()*mWalkSpeed/ densityModifier, pos().y() + mMovementDirection.y()*mWalkSpeed/ densityModifier);
		checkForWalls(newPosition, mWalkSpeed);
		this->setPos(newPosition);
		AddEnergy();
	}
}

void QHumanoid::checkForWalls(QPointF &newPosition, qreal movementSpeed)
{
	//Si on tourne déjà, on continue dans les direction de tournant donné
	if (!mIsTurning)
	{
		//Si on s'en va dans un mur, on ajuste la direction et on calcul les direction a prendre pour faire le tournant au complet
		if ((newPosition.x() < mSizeHumanoid * 2) || (newPosition.x() > ParamSim::SceneWidth() - (mSizeHumanoid * 2)) ||
			(newPosition.y() < mSizeHumanoid * 2) || (newPosition.y() > ParamSim::SceneHeight() - (mSizeHumanoid * 2)))
		{
			mIsTurning = true;
			//On trouve l'angle de mouvement actuel
			qreal directionAngle = atan(mMovementDirection.y() / mMovementDirection.x());
			for (int i{ 0 }; i < mNumberOfTurningDirection; ++i)
			{
				qreal newAngle = directionAngle + (mRotationAngle / mNumberOfTurningDirection);
				QVector2D newDirection(cos(newAngle), sin(newAngle));
				mTurningDirection[i] = newDirection;
			}
			mTurningAtPosition = 1;
			newPosition = QPointF(pos().x() + mTurningDirection[0].x()*movementSpeed, pos().y() + mTurningDirection[0].y()*movementSpeed);
			mMovementDirection = mTurningDirection[0];
		}
	}
}

void QHumanoid::setDirectionTo(QPointF positionTo)
{
	//We set the direction of the entity going to that entity
	qreal movementX = (positionTo.x() - pos().x());
	qreal movementY = (positionTo.y() - pos().y());
	qreal directionNorm = sqrt(movementX*movementX + movementY*movementY);
	mMovementDirection = QVector2D(movementX / directionNorm, movementY / directionNorm);

}

void QHumanoid::setDirectionFrom(QPointF positionFrom)
{
	//We set the direction of the entity going away from that point
	qreal movementX = (pos().x() - positionFrom.x());
	qreal movementY = (pos().y() - positionFrom.y());
	qreal directionNorm = sqrt(movementX*movementX + movementY*movementY);
	mMovementDirection = QVector2D(movementX / directionNorm, movementY / directionNorm);

}

