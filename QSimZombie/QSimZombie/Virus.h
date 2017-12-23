#pragma once
class Virus
{
public:
	Virus();
	Virus(double fatherVirusStrenght);
	~Virus();

	double Strenght();


private:
	int mStrenght;
	int mTicToZombie;
	
	static double mMeanStrenght;
	static double mDevStrenght;
	static int mTimeZombie;

};

