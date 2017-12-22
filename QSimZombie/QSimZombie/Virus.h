#pragma once
class Virus
{
public:
	Virus();
	Virus(double fatherVirusStrenght);
	~Virus();

	double Strenght();
	/*bool IsBecomingZombit();
	void DecTimeRemaining();
	void DecTimeRemaining(int decrement);
	bool WillInfect(int humanStrenght);*/


private:
	int mStrenght;
	int mTicToZombie;
	
	static double mMeanStrenght;
	static double mDevStrenght;
	static int mTimeZombie;

};

