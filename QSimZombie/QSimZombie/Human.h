#ifndef HUMAIN_H
#define HUMAIN_H

#include "QHumanoid.h"
#include "HumanSpecifier.h"
#include "newHumanParameters.h"


class Zombie;
class Woman;
class Virus;
class HumanSpecifier;
class Environnement;

class Human : public QHumanoid
{
public:

	enum class movementSpeed{walk,run};

	Human() = delete;
	Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age = 0, bool military = false, bool infected = false, QGraphicsItem *parent = nullptr);
	Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, bool becomeMilitary = false, bool infected = false, QGraphicsItem *parent = nullptr);
	Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide,newHumanParameters *humanParameters, QGraphicsItem *parent = nullptr);
	~Human();
	void advance(int phase) override;
	void advance(int phase, int const index) override;
	bool IsDead();
	void Reproduction();

	int Age();
	int DeathAge();
	qreal VirusResistance();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	bool IsBecomingZombie(bool biteByZombie = false);
	void IsBecomingAdult();
	void IsRetiring();
	bool isInfected() { return (mVirus) ? true : false; }

	qreal fertility() { return mFertility; }


protected:
	bool VirusTransmission();
	void MilitaryPainter(QPainter * painter);
	void ChildrenPainter(QPainter * painter);
	void InfectedPainter(QPainter * painter);
	void DeleteSpecifier();
	void BaseHumanInit();
	void CreateMilitary();
	void CreateVirus();
	void CreateChild();
	void moveInDirection(movementSpeed movementSpeed);
	void checkForWalls(QPointF &newPosition, qreal movementSpeed);
	void setDirectionTo(QPointF positionTo);
	void setDirectionFrom(QPointF positionFrom);
	int mAge;
	int mDeathAge;
	qreal mVirusResistance;
	qreal mFertility; //Value between 0 and 1
	HumanSpecifier* mSpecifier;
	bool mWillBeocmeMilitary;
	bool mMilitary;
	bool mChildren;
	Virus * mVirus;

private:
	static RandomNorm * mResistanceGenerator;
	static const double mResistanceMean;
	static const double mResistanceDeviation;

	static RandomNorm * mDeathAgeGenerator;
	static const double mDeathAgeMean;
	static const double mDeathAgeDeviation;

	static const QColor mHumanColor;
};


#endif // !HUMAIN_H


