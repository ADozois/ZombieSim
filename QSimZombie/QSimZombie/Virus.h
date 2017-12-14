#pragma once
class Virus
{
public:
	Virus();
	~Virus();

	int Strenght();


private:
	int mStrenght;
	
	static double mMeanStrenght;
	static double mDevStrenght;

};

