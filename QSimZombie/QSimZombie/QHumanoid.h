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
	QHumanoid(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, QGraphicsItem *parent = nullptr);
	~QHumanoid();

	
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void advance(int phase) override;
	virtual void advance(int phase, int index);		//On surcharge advance afin d'introduire l'index de l'humanoide qui doit bouger si nécessaire
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
	humanoideType who() { return mHumanoideType; }

	

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
	Environnement * mEnvironnement;
	humanoideType mHumanoideType;

	const Human * mClosestHuman;

private:
	static RandomNorm *mRunGenerator;
	static RandomNorm *mWalkGenerator;
	static RandomIntUnif *mNameGenerator;
	static QRectF mRectF;

	static const QList<QString> mNameList;
	static const double mWalkDev;
	static const double mRunDev;
	static const int mBeginName;
	static const int mEndName;
	static const double mRectP1;
	static const double mRectP2;
	static const double mRectH;
	static const double mRectW;
	static const double mPenWidth;
};

#endif // !Q_HUMANOID_H


