#ifndef HUMAN_SPECIFIER_H
#define HUMAN_SPECIFIER_H

#include <QObject>

class HumanSpecifier
{
public:
	HumanSpecifier() = default;
	~HumanSpecifier() = default;

public slots:
	virtual void advance(int phase) = 0;
};


#endif // !HUMAN_SPECIFIER_H




