#ifndef HUMAIN_H
#define HUMAIN_H

#include "QHumanoid.h"
#include "HumanSpecifier.h"

class Zombie;
class Woman;
class Virus;

class Human : public QHumanoid
{
public:
	Human(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, Environnement *currentEnvironnemnt,int age = 0, HumanSpecifier *humainSpecifier = nullptr, QGraphicsItem *parent = nullptr);
	~Human();
	void advance(int phase) override;
	bool IsDead();
	void Reproduction();

	int Age();
	int DeathAge();
	int VirusResistance();
	int calculateAllDistance(Environnement * environnement, Zombie *closestZombi);

protected:
	bool IsPossibleMate(Woman * woman);
	bool VirusTransmission();

protected:
	int mAge;
	int mDeathAge;
	int mVirusResistance;
	HumanSpecifier* mSpecifier;

private:
	static RandomNorm * mResistanceGenerator;
	static const double mResistanceMean;
	static const double mResistanceDeviation;

	static RandomNorm * mDeathAgeGenerator;
	static const double mDeathAgeMean;
	static const double mDeathAgeDeviation;
};


#endif // !HUMAIN_H


