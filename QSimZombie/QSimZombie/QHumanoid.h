#ifndef Q_HUMANOID_H
#define Q_HUMANOID_H

#include <QObject>
#include <QGraphicsItem>
#include <QVector2D>
#include "RandomIntUnif.h"
#include "RandomNorm.h"

class Human;
class QRandom;
class Environnement;

class QHumanoid : public QGraphicsItem
{

public:

	enum class humanoideType { human, zombi, woman, children, military };

	QHumanoid() = delete;
	QHumanoid(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, QGraphicsItem *parent = nullptr);
	QHumanoid(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide,qreal runSpeed, qreal walkSpeed, qreal viewRay , QGraphicsItem *parent = nullptr);
	~QHumanoid();

	
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void advance(int phase) override;
	virtual void advance(int phase, int const index);		//On surcharge advance afin d'introduire l'index de l'humanoide qui doit bouger si n�cessaire
	void ReduceEnergy();
	void ReduceEnergy(int loss);
	void AddEnergy();
	void AddEnergy(int gain);
	int Energy(); //Varies from 1 to 100
	qreal ViewRay(); 
	qreal RunSpeed();
	qreal WalkSpeed();
	QString Name();
	qreal RotationAngle();
	QVector2D MouvementDirection();
	humanoideType who() { return mHumanoideType; }
	//qreal eatingDistance() { return static_cast<qreal>(mSizeHumanoid); }

	

protected:
	QVector2D Position();


protected:
	void InitializeVisual(QPainter * painter);

protected:
	int mEnergy;
	qreal mViewRay;
	qreal mViewRaySq;
	qreal mRunSpeed;
	qreal mWalkSpeed;
	QPainter *mPainter;
	QRectF *mBoundingBox;
	QString mName;
	qreal mRotationAngle;
	QVector2D mMovementDirection;
	Environnement * mEnvironnement;
	humanoideType mHumanoideType;
	QVector2D mPosition;
	QRectF mRectF;
	QColor mBrushColor;
	QColor mPenColor;

	bool mIsTurning;
	QVector2D *mTurningDirection;
	int mTurningAtPosition;
	static const int mNumberOfTurningDirection{ 5 };

	//const Human * mClosestHuman;
	static const qreal mEatingRange;
	static const int mSizeHumanoid;
	

private:
	static RandomNorm *mRunGenerator;
	static RandomNorm *mWalkGenerator;
	static RandomNorm *mRayGenerator;
	static RandomIntUnif *mNameGenerator;

	static const QList<QString> mNameList;
	static const double mWalkDev;
	static const double mRayDev;
	static const double mOffsetRun;
	static const double mRunDev;
	static const int mBeginName;
	static const int mEndName;
	static const double mRectP1;
	static const double mRectP2;
	static const double mRectH;
	static const double mRectW;
	static const double mPenWidth;
	static const QColor mHumanoidColor;
	static const QColor mContourColor;	
	static const double mOpacityHumanoid;
	
};

#endif // !Q_HUMANOID_H


