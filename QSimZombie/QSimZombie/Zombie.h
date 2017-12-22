#pragma once
#include "QHumanoid.h"
class Zombie : public QHumanoid
{
public:
	Zombie() = delete;
	Zombie(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, QGraphicsItem *parent = nullptr);
	~Zombie();
	void advance(int phase) override;
	void advance(int phase, int index) override;
	bool attack(QGraphicsItem * Human);

private:
	static RandomIntUnif * mDeathGenerator;

	static const int mBegin;
	static const int mEnd;
	static const int mAttackThreshold;
};

