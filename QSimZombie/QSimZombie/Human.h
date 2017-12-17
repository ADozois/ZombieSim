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
	Human(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide,int age = 0, HumanSpecifier *humainSpecifier = nullptr, QGraphicsItem *parent = nullptr);
	~Human();
	void advance(int phase) override;
	void advance(int phase, int index) override;
	bool IsDead();
	void Reproduction();

	int Age();
	int DeathAge();
	int VirusResistance();

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


