#ifndef HUMAN_SPECIFIER_H
#define HUMAN_SPECIFIER_H


class HumanSpecifier
{
public:
	HumanSpecifier() = default;
	~HumanSpecifier() = default;


	enum class returnAdvance { noAction, newAdult,endMilitary };

	virtual returnAdvance advance(int phase) = 0;
	virtual returnAdvance advance(int phase, int const index) = 0;
};


#endif // !HUMAN_SPECIFIER_H




