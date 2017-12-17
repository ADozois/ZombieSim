#ifndef Q_HUMANOID_H
#define Q_HUMANOID_H

#include <QObject>
#include <QGraphicsItem>
#include <QVector2D>
#include "RandomIntUnif.h"
#include "RandomNorm.h"

class Human;
class QRandom;

class QHumanoid : public QGraphicsItem
{

public:
	QHumanoid() = delete;
	QHumanoid(double x, double y, QGraphicsItem *parent = nullptr);
	~QHumanoid();

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void advance(int phase) override;
	void ReduceEnergy();
	void ReduceEnergy(int loss);
	void AddEnergy();
	void AddEnergy(int gain);
	int Energy();
	qreal ViewRay();
	qreal RunSpeed();
	qreal WalkSpeed();
	QString Name();
	qreal RotationAngle();
	QVector2D MouvementDirection();
	QVector2D Position();


protected:
	void InitializeVisual(QPainter * painter);

protected:
	int mEnergy;
	qreal mViewRay;
	qreal mRunSpeed;
	qreal mWalkSpeed;
	QPainter *mPainter;
	QRectF *mBoundingBox;
	QString mName;
	qreal mRotationAngle;
	QVector2D mMouvementDirection;
	QVector2D mPosition;
	QRectF mRectF;
	QColor mBrushColor;
	QColor mPenColor;

	const Human * mClosestHuman;

	static RandomNorm *mRunGenerator;
	static RandomNorm *mWalkGenerator;
	static RandomIntUnif *mNameGenerator;

	static const QList<QString> mNameList;
	static const double mWalkDev;
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
	static const int mSizeHumanoid;
	static const double mOpacityHumanoid;
};

#endif // !Q_HUMANOID_H


