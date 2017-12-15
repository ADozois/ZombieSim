#pragma once
#include "QHumanoid.h"
class Zombie : public QHumanoid
{
public:
	Zombie() = delete;
	Zombie(double x, double y, QGraphicsItem *parent = nullptr);
	~Zombie() = default;
	void advance(int phase) override;
	bool attack(QGraphicsItem * Human);

private:
	static RandomIntUnif * mDeathGenerator;

	static const int mBegin;
	static const int mEnd;
	static const int mAttackThreshold;
};

