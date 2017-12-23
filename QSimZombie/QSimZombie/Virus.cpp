#include "Virus.h"
#include"RandomNorm.h"

double Virus::mMeanStrenght{70.0};
double Virus::mDevStrenght{0.3};
int Virus::mTimeZombie{0};

Virus::Virus()
	:mStrenght{static_cast<int>(std::ceil(RandomNorm::Generate(mMeanStrenght, mMeanStrenght*mDevStrenght)))}
{
}

Virus::Virus(double fatherVirusStrenght)
	: mStrenght{ static_cast<int>(std::ceil(RandomNorm::Generate(fatherVirusStrenght, fatherVirusStrenght*mDevStrenght))) }
{
}

Virus::~Virus()
{
}

double Virus::Strenght()
{
	return mStrenght;
}
