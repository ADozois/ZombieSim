#pragma once
#include "QHumanoid.h"
class Zombie : public QHumanoid
{
public:
	Zombie() = delete;
	Zombie(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, QGraphicsItem *parent = nullptr);
	~Zombie();
	void advance(int phase) override;
	void advance(int phase, int const index) override;
	void attack(Human * attackedHuman, int const index);

private:
	static RandomIntUnif * mDeathGenerator;

	static const int mBegin;
	static const int mEnd;
	static const int mAttackThreshold;
};

