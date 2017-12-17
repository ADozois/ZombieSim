#ifndef HUMAIN_H
#define HUMAIN_H

#include "QHumanoid.h"


class Zombie;
class Woman;
class Virus;
class HumanSpecifier;

class Human : public QHumanoid
{
public:
	Human(double x, double y, int age = 0, bool military = false, bool infected = false, QGraphicsItem *parent = nullptr);
	~Human();
	void advance(int phase) override;
	bool IsDead();
	void Reproduction();

	int Age();
	int DeathAge();
	int VirusResistance();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;



protected:
	bool IsPossibleMate(Woman * woman);
	bool VirusTransmission();
	void MilitaryPainter(QPainter * painter);
	void ChildrenPainter(QPainter * painter);
	void InfectedPainter(QPainter * painter);

protected:
	int mAge;
	int mDeathAge;
	int mVirusResistance;

	HumanSpecifier * mSpecifier;
	Virus * mVirus;

	static RandomNorm * mResistanceGenerator;
	static const double mResistanceMean;
	static const double mResistanceDeviation;

	static RandomNorm * mDeathAgeGenerator;
	static const double mDeathAgeMean;
	static const double mDeathAgeDeviation;

	static const QColor mHumanColor;
};


#endif // !HUMAIN_H


