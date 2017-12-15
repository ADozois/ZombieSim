#ifndef HUMAIN_H
#define HUMAIN_H

#include "QHumanoid.h"

class Zombie;
class Woman;
class Virus;

class Human : public QHumanoid
{
public:
	Human(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, int age = 0, QGraphicsItem *parent = nullptr);
	~Human();
	void advance(int phase) override;
	bool IsDead();
	void Reproduction();

	int Age();
	int DeathAge();
	int VirusResistance();

protected:
	bool IsPossibleMate(Woman * woman);
	bool VirusTransmission();

private:
	int mAge;
	int mDeathAge;
	int mVirusResistance;

	static RandomNorm * mResistanceGenerator;
	static const double mResistanceMean;
	static const double mResistanceDeviation;

	static RandomNorm * mDeathAgeGenerator;
	static const double mDeathAgeMean;
	static const double mDeathAgeDeviation;
};


#endif // !HUMAIN_H


