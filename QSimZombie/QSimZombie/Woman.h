#ifndef WOMAN_H
#define WOMAN_H

#include "Human.h"

class Children;

class Woman : public Human
{
public:
	Woman() = delete;
	Woman(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age = 0, bool military = false, bool infection = false, QGraphicsItem *parent = nullptr);
	~Woman();
	Children* GiveBirth();
	int CountChildren();
	bool Reproduction();
	void LosingChild(Children * child);
	void advance(int phase) override;
	void advance(int phase, int index) override;



private:
	QList<Children *> mListChildren;
	bool mReproduction;
	int mCountChildren;
	int mTickRemaining;

	static int mMaxChildren;
	
	static const int mEndFertility;
	static const int mFertilityTime;
	static const QColor mWomanColor;
};


#endif // !WOMAN_H

