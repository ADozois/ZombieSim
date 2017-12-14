#pragma once
#include "QHumanoid.h"
class Zombie : public QHumanoid
{
public:
	Zombie() = delete;
	Zombie(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, QGraphicsItem *parent = nullptr);
	~Zombie() = default;
	void advance(int phase) override;
	bool attack(QGraphicsItem * Human);

private:
	static RandomIntUnif * mDeathGenerator;

	static const int mBegin;
	static const int mEnd;
	static const int mAttackThreshold;
};

