#ifndef Q_PARAM_SIM_H
#define Q_PARAM_SIM_H


class QParametersTab;

class ParamSim
{
public:

	ParamSim() = default;
	~ParamSim() = default;
	static int NbrZombie(void) { return mNbrZombie; }
	static int NbrHuman(void) { return mNbrHuman; }
	static int NbrWoman(void) { return mNbrWoman; }
	static int NbrMilitary(void) { return mNbrMilitary; }
	static int NbrVirus(void) { return mNbrVirus; }
	static int SceneHeight(void) { return mSceneHeight; }
	static int SceneWidth(void) { return mSceneWidth; }
	static int ViewHeight(void) { return mViewHeight; }
	static int ViewWidth(void) { return mViewWidth; }
	static int NbrCity(void) { return mNbrCity; }
	static int MeanAge(void) { return mMeanAge; }
	static double ViewRay() { return mViewRay; };
	static double RotationAngle() { return mRotationAngle; };
	static double VirusResistance(void) { return mVirusResistance; }
	static double MeanVirusForce(void) { return mMeanVirusForce; }
	static double ProbNewMilitary(void) { return mProbNewMilitary; }
	static double ProbReproduction(void) { return mProbReproduction; }
	static double ProbWoman(void) { return mProbWoman; }
	static double ProbInfection(void) { return mProbInfection; }
	static double ComssumptionRateEnergieHuman(void) { return mComssumptionRateEnergieHuman; }
	static double ComssumptionRateEnergieZombie(void) { return mComssumptionRateEnergieZombie; }
	static int PregnancyTime(void) { return mPregnancyTime; }
	static double ProbSpeed(void) { return mProbSpeed; }

	static void setNbrZombie(int nbr);
	static void setNbrHuman(int nbr);
	static void setNbrWoman(int nbr);
	static void setNbrMilitary(int nbr);
	static void setNbrVirus(int nbr);
	static void setSceneHeight(int heigth);
	static void setSceneWidth(int width);
	static void setViewHeight(int heigth);
	static void setViewWidth(int width);
	static void setNbrCity(int nbr);
	static void setMeanAge(int mean);
	static void setViewRay(double viewRay);
	static void setRotationAngle(double rotationAngle);
	static void setVirusResistance(double resistance);
	static void setMeanVirusForce(double meanForce);
	static void setProbNewMilitary(double probMil);
	static void setProbReproduction(double probRepro);
	static void setProbWoman(double probWoman);
	static void setProbInfection(double probInfect);
	static void setComssumptionRateEnergieHuman(double rate);
	static void setComssumptionRateEnergieZombie(double rate);
	static void setPregnancyTime(int time);
	static void setProbSpeed(double speed);

private:
	static int mNbrZombie;
	static int mNbrHuman;
	static int mNbrWoman;
	static int mNbrMilitary;
	static int mNbrVirus;
	static int mSceneHeight;
	static int mSceneWidth;
	static int mViewHeight;
	static int mViewWidth;
	static int mNbrCity;
	static int mMeanAge;
	static int mPregnancyTime;
	
	static double mViewRay;
	static double mRotationAngle;
	static double mVirusResistance;
	static double mMeanVirusForce;
	static double mProbNewMilitary;
	static double mProbReproduction;
	static double mProbWoman;
	static double mProbInfection;
	static double mComssumptionRateEnergieHuman;
	static double mComssumptionRateEnergieZombie;
	static double mProbSpeed;
	
};

#endif