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
//
//bool Virus::IsBecomingZombit()
//{
//	if (mTicToZombie <= mTimeZombie)
//	{
//		return true;
//	}
//	return false;
//}
//
//void Virus::DecTimeRemaining()
//{
//	mTicToZombie--;
//}
//
//void Virus::DecTimeRemaining(int decrement)
//{
//	mTicToZombie -= decrement;
//}
//
//bool Virus::WillInfect(int humanStrenght)
//{
//	if (mStrenght > humanStrenght)
//	{
//		return true;
//	}
//	return false;
//}
