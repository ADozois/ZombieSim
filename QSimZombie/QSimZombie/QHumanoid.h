#ifndef Q_HUMANOID_H
#define Q_HUMANOID_H

#include <QObject>
#include <QGraphicsItem>
#include<QVector2D>

class Human;
class QRandom;

class QHumanoid : public QGraphicsItem
{
	//Q_OBJECT

public:
	QHumanoid(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, QGraphicsItem *parent = nullptr);
	~QHumanoid();

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
	int mEnergy;
	qreal mViewRay;
	qreal mRunSpeed;
	qreal mWalkSpeed;
	QPainter *mPainter;
	QRectF *mBoundingBox;
	QString mName;
	qreal mRotationAngle;
	QVector2D mMovementDirection;

	const Human * mClosestHuman;

	static QRandom *mSpeedGenerator;
	static QRandom *mNameGenerator;
	static const QList<QString> mNameList;
};

#endif // !Q_HUMANOID_H


