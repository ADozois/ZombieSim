#ifndef HUMAN_SPECIFIER_H
#define HUMAN_SPECIFIER_H

#include <QObject>
#include "Human.h"

class HumanSpecifier
{
public:
	HumanSpecifier() = default;
	~HumanSpecifier() = default;

public:
	virtual Human::returnAdvance advance(int phase) = 0;
	virtual Human::returnAdvance advance(int phase, int index) = 0;
};


#endif // !HUMAN_SPECIFIER_H




