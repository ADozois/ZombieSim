
#ifndef Q_PARAM_SIM_H
#define Q_PARAM_SIM_H

class ParamSim
{
public:

	ParamSim() = default;
	~ParamSim() = default;
	int NbrZombie(void) { return mNbrZombie; }
	int NbrHuman(void) { return mNbrHuman; }
	int NbrWoman(void) { return mNbrWoman; }
	int NbrMilitary(void) { return mNbrMilitary; }
	int NbrVirus(void) { return mNbrVirus; }
	int SceneHeight(void) { return mSceneHeight; }
	int SceneWidth(void) { return mSceneWidth; }
	int ViewHeight(void) { return mViewHeight; }
	int ViewWidth(void) { return mViewWidth; }
	int NbrCity(void) { return mNbrCity; }
	int MeanAge(void) { return mMeanAge; }
	double VirusResistance(void) { return mVirusResistance; }
	double MeanVirusForce(void) { return mMeanVirusForce; }
	double ProbNewMilitary(void) { return mProbNewMilitary; }
	double ProbReproduction(void) { return mProbReproduction; }
	double ProbWoman(void) { return mProbWoman; }
	double ProbInfection(void) { return mProbInfection; }
	double ComssumptionRateEnergieHuman(void) { return mComssumptionRateEnergieHuman; }
	double ComssumptionRateEnergieZombie(void) { return mComssumptionRateEnergieZombie; }
	int PregnancyTime(void) { return mPregnancyTime; }
	double ProbSpeed(void) { return mProbSpeed; }

	void setNbrZombie(int nbr);
	void setNbrHuman(int nbr);
	void setNbrWoman(int nbr);
	void setNbrMilitary(int nbr);
	void setNbrVirus(int nbr);
	void setSceneHeight(int heigth);
	void setSceneWidth(int width);
	void setViewHeight(int heigth);
	void setViewWidth(int width);
	void setNbrCity(int nbr);
	void setMeanAge(int mean);
	void setVirusResistance(double resistance);
	void setMeanVirusForce(double meanForce);
	void setProbNewMilitary(double probMil);
	void setProbReproduction(double probRepro);
	void setProbWoman(double probWoman);
	void setProbInfection(double probInfect);
	void setComssumptionRateEnergieHuman(double rate);
	void setComssumptionRateEnergieZombie(double rate);
	void setPregnancyTime(int time);
	void setProbSpeed(double speed);

private:
	int mNbrZombie;
	int mNbrHuman;
	int mNbrWoman;
	int mNbrMilitary;
	int mNbrVirus;
	int mSceneHeight;
	int mSceneWidth;
	int mViewHeight;
	int mViewWidth;
	int mNbrCity;
	int mMeanAge;
	int mPregnancyTime;

	double mVirusResistance;
	double mMeanVirusForce;
	double mProbNewMilitary;
	double mProbReproduction;
	double mProbWoman;
	double mProbInfection;
	double mComssumptionRateEnergieHuman;
	double mComssumptionRateEnergieZombie;
	double mProbSpeed;

};

#endif