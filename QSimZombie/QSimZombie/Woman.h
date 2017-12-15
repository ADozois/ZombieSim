#ifndef WOMAN_H
#define WOMAN_H

#include "Human.h"

class Children;

class Woman : public Human
{
public:
	Woman(qreal viewRay, qreal rotationAngle, qreal walkSpeed, qreal runSpeed, int age = 18, QGraphicsItem *parent = nullptr);
	~Woman();
	Children* GiveBirth();
	int CountChildren();
	bool Reproduction();
	void LosingChild(Children * child);


private:
	QList<Children *> mListChildren;
	bool mReproduction;
	int mCountChildren;
	int mTickRemaining;

	static int mMaxChildren;
	
	static const int mEndFertility;
	static const int mFertilityTime;
};


#endif // !WOMAN_H

