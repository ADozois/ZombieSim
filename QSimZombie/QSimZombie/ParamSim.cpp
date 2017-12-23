#include "ParamSim.h"
#include "QParametersTab.h"

int ParamSim::mNbrZombie{ 0 };
int ParamSim::mNbrHuman{ 0 };
int ParamSim::mNbrWoman{ 0 };
int ParamSim::mNbrMilitary{ 0 };
int ParamSim::mNbrVirus{ 0 };
int ParamSim::mSceneHeight{ 700 };
int ParamSim::mSceneWidth{ 1000 };
int ParamSim::mViewHeight{ 700 };
int ParamSim::mViewWidth{ 1000 };
int ParamSim::mNbrCity{ 5 };
int ParamSim::mMeanAge{ 0 };
int ParamSim::mPregnancyTime{ 0 };

double ParamSim::mViewRay{ 0.0 };
double ParamSim::mRotationAngle{ 0.0 };
double ParamSim::mVirusResistance{ 0.0 };
double ParamSim::mMeanVirusForce{ 0.0 };
double ParamSim::mProbNewMilitary{ 0.0 };
double ParamSim::mProbReproduction{ 0.0 };
double ParamSim::mProbWoman{ 0.0 };
double ParamSim::mProbInfection{ 20.0 };
double ParamSim::mComssumptionRateEnergieHuman{ 0.0 };
double ParamSim::mComssumptionRateEnergieZombie{ 0.0 };
double ParamSim::mProbSpeed{ 0.0 };


void ParamSim::setNbrZombie(int nbr) {
	mNbrZombie = nbr;
}

void ParamSim::setNbrHuman(int nbr) {
	mNbrHuman = nbr;
}

void ParamSim::setNbrWoman(int nbr) {
	mNbrWoman = nbr;
}

void ParamSim::setNbrMilitary(int nbr) {
	mNbrMilitary = nbr;
}

void ParamSim::setNbrVirus(int nbr) {
	mNbrVirus = nbr;
}

void ParamSim::setSceneHeight(int heigth) {
	mSceneHeight = heigth;
}

void ParamSim::setSceneWidth(int width) {
	mSceneWidth = width;
}
void ParamSim::setViewHeight(int heigth) {
	mViewHeight = heigth;
}

void ParamSim::setViewWidth(int width) {
	mViewWidth = width;
}

void ParamSim::setNbrCity(int nbr) {
	mNbrCity = nbr;
}

void ParamSim::setMeanAge(int mean) {
	mMeanAge = mean;
}

void ParamSim::setViewRay(double viewRay)
{
	mViewRay = viewRay;
}

void ParamSim::setRotationAngle(double rotationAngle)
{
	mRotationAngle = rotationAngle;
}

void ParamSim::setVirusResistance(double resistance) {
	mVirusResistance = resistance;
}

void ParamSim::setMeanVirusForce(double meanForce) {
	mMeanVirusForce = meanForce;
}

void ParamSim::setProbNewMilitary(double probMil) {
	mProbNewMilitary = probMil;
}

void ParamSim::setProbReproduction(double probRepro) {
	mProbReproduction = probRepro;
}

void ParamSim::setProbWoman(double probWoman) {
	mProbWoman = probWoman;
}

void ParamSim::setProbInfection(double probInfect) {
	mProbInfection = probInfect;
}

void ParamSim::setComssumptionRateEnergieHuman(double rate) {
	mComssumptionRateEnergieHuman = rate;
}

void ParamSim::setComssumptionRateEnergieZombie(double rate) {
	mComssumptionRateEnergieZombie = rate;
}

void ParamSim::setPregnancyTime(int time) {
	mPregnancyTime = time;
}
void ParamSim::setProbSpeed(double speed) {
	mProbSpeed = speed;
}


