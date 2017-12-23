#include "QParametersTab.h"
#include "ParamSim.h"


//QStrings for parameters
//Entity Quantities
const QString QParametersTab::mZombieCountString{ "Zombie Count" };
const QString QParametersTab::mHumanCountString{ "Human Count" };
const QString QParametersTab::mWomanCountString{ "Woman Count" };
const QString QParametersTab::mMilitaryCountString{ "Military Count" };
const QString QParametersTab::mVirusCountString{ "Virus Count" };
const QString QParametersTab::mCityCountString{ "City Count" };

//Entity Caracteristics
const QString QParametersTab::mAverageAgeString{ "Average Age" };
const QString QParametersTab::mAverageSpeedString{ "Average Speed" };
const QString QParametersTab::mAverageVirusResistanceString{ "Average Virus Resistance" };
const QString QParametersTab::mReproductionProbabilityString{ "Reproduction Probability" };
const QString QParametersTab::mPregnancyDurationString{ "Pregnancy Duration" };
const QString QParametersTab::mNewMilitaryProbabilityString{ "New Military Probability" };
const QString QParametersTab::mWomanProbabilityString{ "Woman Probability" };

//Scene Parameter Strings
const QString QParametersTab::mSceneHeightString{ "Scene Height" };
const QString QParametersTab::mSceneWidthString{ "Scene Width" };
const QString QParametersTab::mViewHeightString{ "View Height" };
const QString QParametersTab::mViewWidthString{ "View Width" };

//Environment Parameter Strings
const QString QParametersTab::mInfectionProbabilityString{ "Infection Probability" };
const QString QParametersTab::mAverageVirusStrenghtString{ "Average Virus Strenght" };
const QString QParametersTab::mHumanEnergyDropRateString{ "Human Energy Drop Rate" };
const QString QParametersTab::mZombieEnergyDropRateString{ "Zombie Energy Drop Rate" };
const QString QParametersTab::mProbSpeedString{ "Speed probability" };
const QString QParametersTab::mViewRayString{ "View Ray" };
const QString QParametersTab::mRotationAngleString{ "Rotation Angle" };


QParametersTab::QParametersTab(QWidget *parent)
	: QWidget(parent)
{


	//Create things
	//Layouts
	mMainLayout = new QHBoxLayout;
	mMainLayout2 = new QVBoxLayout;
	mValidateLayout = new QHBoxLayout;
	mLeftLayout = new QVBoxLayout;
	mRightLayout = new QVBoxLayout;

	mEntityQtyGBL = new QFormLayout;
	mEntityCarGBL = new QFormLayout;
	mEnvironmentCarGBL = new QFormLayout;
	mSceneParamGBL = new QFormLayout;

	//GroupBox
	mEntityQtyGB = new QGroupBox(tr("Entity Quantities"));
	mEntityCarGB = new QGroupBox(tr("Entity Caracteristics"));
	mEnvironmentCarGB = new QGroupBox(tr("Environment Caracteristics"));
	mSceneParamGB = new QGroupBox(tr("Scene Parameters"));

	//Labels
	mZombieCountLabel = new QLabel(mZombieCountString);
	mHumanCountLabel = new QLabel(mHumanCountString);

	//Main layouts (left/right)
	mMainLayout2->addLayout(mMainLayout);
	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->addLayout(mRightLayout);

	//Add groupboxed parameters to layouts
	mLeftLayout->addWidget(mEntityQtyGB);
	mLeftLayout->addWidget(mEntityCarGB);

	//Add generate button
	mValidateButton = new QPushButton("Validate");
	//mValidate->set
	mMainLayout2->addLayout(mValidateLayout);

	mValidateLayout->addStretch();
	mValidateLayout->addWidget(mValidateButton);
	mValidateLayout->addStretch();




	mRightLayout->addWidget(mEnvironmentCarGB);
	mRightLayout->addWidget(mSceneParamGB);

	//Each GroupBox has its Layout
	mEntityQtyGB->setLayout(mEntityQtyGBL);
	mEntityCarGB->setLayout(mEntityCarGBL);
	mEnvironmentCarGB->setLayout(mEnvironmentCarGBL);
	mSceneParamGB->setLayout(mSceneParamGBL);

	//Parameter Spinboxes and Sliders
	//Entity Count
	mZombieCount = new QSpinBox;
	mZombieCount->setToolTip("Set the number of roaming zombies");
	mZombieCount->setRange(entityMinimum, entityMaximum);

	mHumanCount = new QSpinBox;
	mHumanCount->setToolTip("Set the initial number of humans");
	mHumanCount->setRange(entityMinimum, entityMaximum);

	mWomanCount = new QSpinBox;
	mWomanCount->setToolTip("Set the initial number of women");
	mWomanCount->setRange(entityMinimum, entityMaximum); //Faudra g�rer que mWomanCount + mMilitaryCount <= mHumanCount

	mMilitaryCount = new QSpinBox;
	mMilitaryCount->setToolTip("Set the initial number of military");
	mMilitaryCount->setRange(entityMinimum, entityMaximum);

	mVirusCount = new QSpinBox;
	mVirusCount->setToolTip("Set the initial virus count");
	mVirusCount->setRange(entityMinimum, entityMaximum);

	mCityCount = new QSpinBox;
	mCityCount->setToolTip("Set the initial virus count");
	mCityCount->setRange(entityMinimum, entityMaximum);


	//Entity Caracteristics
	mAverageAge = new QSliderAffiche(Qt::Horizontal), mAverageAge->setToolTip("Set the initial Average Age");
	mAverageAge->setRange(10, 80);
	mAverageSpeed = new QSliderAffiche(Qt::Horizontal), mAverageSpeed->setToolTip("Set the initial Average Speed");
	mAverageSpeed->setRange(10, 50);
	mAverageVirusResistance = new QSliderAffiche(Qt::Horizontal), mAverageVirusResistance->setToolTip("Set the initial Average Virus Resistance");
	mAverageSpeed->setRange(0, 100);
	mReproductionProbability = new QSliderAffiche(Qt::Horizontal), mReproductionProbability->setToolTip("Set the initial Reproduction Probability");
	mReproductionProbability->setRange(20, 80);
	mPregnancyDuration = new QSliderAffiche(Qt::Horizontal), mPregnancyDuration->setToolTip("Set the initial Pregnancy Duration");
	mPregnancyDuration->setRange(1, 12);
	mNewMilitaryProbability = new QSliderAffiche(Qt::Horizontal), mNewMilitaryProbability->setToolTip("Set the probability of a New Military");
	mNewMilitaryProbability->setRange(10, 90);
	mWomanProbability = new QSliderAffiche(Qt::Horizontal), mWomanProbability->setToolTip("Set the probability of a woman");
	mWomanProbability->setRange(10, 90);
	mProbSpeed = new QSliderAffiche(Qt::Horizontal), mProbSpeed->setToolTip("Set the speed variable");
	mProbSpeed->setRange(20, 80);

	//Scene Parameters
	mSceneHeight = new QSliderAffiche(Qt::Horizontal), mSceneHeight->setToolTip("Set the Scene Height");
	mSceneHeight->setRange(500, 1000);
	mSceneWidth = new QSliderAffiche(Qt::Horizontal), mSceneWidth->setToolTip("Set the Scene Width");
	mSceneWidth->setRange(500, 1000);
	mViewHeight = new QSliderAffiche(Qt::Horizontal), mViewHeight->setToolTip("Set the View Height");
	mViewHeight->setRange(500, 1000);
	mViewWidth = new QSliderAffiche(Qt::Horizontal), mViewWidth->setToolTip("Set the View Width");
	mViewWidth->setRange(500, 1000);

	//Environment parameters
	mInfectionProbability = new QSliderAffiche(Qt::Horizontal), mInfectionProbability->setToolTip("Set the Infection Probability");
	mInfectionProbability->setRange(10, 900);
	mAverageVirusStrenght = new QSliderAffiche(Qt::Horizontal), mAverageVirusStrenght->setToolTip("Set the Average Virus Strenght");
	mAverageVirusStrenght->setRange(0, 100);
	mHumanEnergyDropRate = new QSliderAffiche(Qt::Horizontal), mHumanEnergyDropRate->setToolTip("Set the initial Human Energy Drop Rate");
	mHumanEnergyDropRate->setRange(10, 80);
	mZombieEnergyDropRate = new QSliderAffiche(Qt::Horizontal), mZombieEnergyDropRate->setToolTip("Set the initial Zombie Energy Drop Rate");
	mZombieEnergyDropRate->setRange(10, 80);
	mViewRay = new QSliderAffiche(Qt::Horizontal), mViewRay->setToolTip("Set the view ray in this environment");
	mViewRay->setRange(10, 100);
	mRotationAngle = new QSliderAffiche(Qt::Horizontal), mRotationAngle->setToolTip("Set the rotation angle");
	mRotationAngle->setRange(10, 50);


	//AddRows to formlayouts
	//Entity Quantities
	mEntityQtyGBL->addRow(mZombieCountString, mZombieCount);
	mEntityQtyGBL->addRow(mHumanCountString, mHumanCount);
	mEntityQtyGBL->addRow(mWomanCountString, mWomanCount);
	mEntityQtyGBL->addRow(mMilitaryCountString, mMilitaryCount);
	mEntityQtyGBL->addRow(mVirusCountString, mVirusCount);
	mEntityQtyGBL->addRow(mCityCountString, mCityCount);

	//Scene Parameters
	mSceneParamGBL->addRow(mSceneHeightString, mSceneHeight);
	mSceneParamGBL->addRow(mSceneWidthString, mSceneWidth);
	mSceneParamGBL->addRow(mViewHeightString, mViewHeight);
	mSceneParamGBL->addRow(mViewWidthString, mViewWidth);

	//Entity Caracteristics
	mEntityCarGBL->addRow(mAverageAgeString, mAverageAge);
	mEntityCarGBL->addRow(mAverageSpeedString, mAverageSpeed);
	mEntityCarGBL->addRow(mReproductionProbabilityString, mReproductionProbability);
	mEntityCarGBL->addRow(mPregnancyDurationString, mPregnancyDuration);
	mEntityCarGBL->addRow(mNewMilitaryProbabilityString, mNewMilitaryProbability);
	mEntityCarGBL->addRow(mWomanProbabilityString, mWomanProbability);
	mEnvironmentCarGBL->addRow(mProbSpeedString, mProbSpeed);



	//Environment Parameters
	mEnvironmentCarGBL->addRow(mInfectionProbabilityString, mInfectionProbability);
	mEnvironmentCarGBL->addRow(mAverageVirusStrenghtString, mAverageVirusStrenght);
	mEnvironmentCarGBL->addRow(mAverageVirusResistanceString, mAverageVirusResistance);
	mEnvironmentCarGBL->addRow(mHumanEnergyDropRateString, mHumanEnergyDropRate);
	mEnvironmentCarGBL->addRow(mZombieEnergyDropRateString, mZombieEnergyDropRate);
	mEnvironmentCarGBL->addRow(mViewRayString, mViewRay);
	mEnvironmentCarGBL->addRow(mRotationAngleString, mRotationAngle);

	setLayout(mMainLayout2);
}


void QParametersTab::updateParameters()
{

	ParamSim::setNbrZombie(mZombieCount->value());
	ParamSim::setNbrWoman(mWomanCount->value());
	ParamSim::setNbrMilitary(mMilitaryCount->value());
	ParamSim::setNbrVirus(mVirusCount->value());
	ParamSim::setNbrHuman(mHumanCount->value());
	ParamSim::setNbrCity(mCityCount->value());
	ParamSim::setSceneHeight(mSceneHeight->value());
	ParamSim::setSceneWidth(mSceneWidth->value());
	ParamSim::setViewHeight(mViewHeight->value());
	ParamSim::setViewWidth(mViewWidth->value());
	ParamSim::setMeanAge(mAverageAge->value());
	ParamSim::setViewRay(mViewRay->value());
	ParamSim::setRotationAngle(mRotationAngle->value());
	ParamSim::setVirusResistance(mAverageVirusResistance->value());
	ParamSim::setMeanVirusForce(mAverageVirusStrenght->value());
	ParamSim::setProbNewMilitary(mNewMilitaryProbability->value());
	ParamSim::setProbReproduction(mReproductionProbability->value());
	ParamSim::setProbWoman(mWomanProbability->value());
	ParamSim::setProbInfection(mInfectionProbability->value());
	ParamSim::setComssumptionRateEnergieHuman(mHumanEnergyDropRate->value());
	ParamSim::setComssumptionRateEnergieZombie(mZombieEnergyDropRate->value());
	ParamSim::setPregnancyTime(mPregnancyDuration->value());
	ParamSim::setProbSpeed(mProbSpeed->value());

}

