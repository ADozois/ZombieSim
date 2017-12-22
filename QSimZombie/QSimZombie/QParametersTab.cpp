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
const QString QParametersTab::mAverageAgeString{"Average Age"};
const QString QParametersTab::mAverageSpeedString{"Average Speed"};
const QString QParametersTab::mAverageVirusResistanceString{"Average Virus Resistance"};
const QString QParametersTab::mReproductionProbabilityString{"Reproduction Probability"};
const QString QParametersTab::mPregnancyDurationString{"Pregnancy Duration"};
const QString QParametersTab::mNewMilitaryProbabilityString{"New Military Probability"};
const QString QParametersTab::mWomanProbabilityString{"Woman Probability"};

//Scene Parameter Strings
const QString QParametersTab::mSceneHeightString{ "Scene Height" };
const QString QParametersTab::mSceneWidthString{ "Scene Width" };
const QString QParametersTab::mViewHeightString{ "View Height" };
const QString QParametersTab::mViewWidthString{ "View Width" };

//Environment Parameter Strings
const QString QParametersTab::mInfectionProbabilityString{ "Infection Probability" };
const QString QParametersTab::mAverageVirusStrenghtString{ "Average Virus Strenght" };
const QString QParametersTab::mHumanEnergyDropRateString{"Human Energy Drop Rate"};
const QString QParametersTab::mZombieEnergyDropRateString{"Zombie Energy Drop Rate"};
const QString QParametersTab::mProbSpeedString{ "Speed probability" };
const QString QParametersTab::mViewRayString{ "View Ray" };
const QString QParametersTab::mRotationAngleString{ "Rotation Angle" };


QParametersTab::QParametersTab(QWidget *parent)
	: QWidget(parent)
{

	
										//Create things
	//Layouts
	mMainLayout = new QHBoxLayout;
	mLeftLayout = new QVBoxLayout;
	mRightLayout = new QVBoxLayout;

	mEntityQtyGBL  = new QFormLayout;
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
	mMainLayout->addLayout(mLeftLayout);
	mMainLayout->addLayout(mRightLayout);

	//Add groupboxed parameters to layouts
	mLeftLayout->addWidget(mEntityQtyGB);
	mLeftLayout->addWidget(mEntityCarGB);

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
	mWomanCount->setRange(entityMinimum, entityMaximum); //Faudra gérer que mWomanCount + mMilitaryCount <= mHumanCount

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
	mAverageAge = new QSliderAffiche(Qt::Horizontal),mAverageAge->setToolTip("Set the initial Average Age");
	mAverageSpeed = new QSliderAffiche(Qt::Horizontal),mAverageSpeed->setToolTip("Set the initial Average Speed");
	mAverageVirusResistance =  new QSliderAffiche(Qt::Horizontal), mAverageVirusResistance->setToolTip("Set the initial Average Virus Resistance");
	mReproductionProbability = new QSliderAffiche(Qt::Horizontal), mReproductionProbability->setToolTip("Set the initial Reproduction Probability");
	mPregnancyDuration = new QSliderAffiche(Qt::Horizontal), mPregnancyDuration->setToolTip("Set the initial Pregnancy Duration");
	mNewMilitaryProbability = new QSliderAffiche(Qt::Horizontal), mNewMilitaryProbability->setToolTip("Set the probability of a New Military");
	mWomanProbability = new QSliderAffiche(Qt::Horizontal),mWomanProbability->setToolTip("Set the probability of a woman");
	mProbSpeed = new QSliderAffiche(Qt::Horizontal), mProbSpeed->setToolTip("Set the speed variable");

	//Scene Parameters
	mSceneHeight = new QSliderAffiche(Qt::Horizontal),mSceneHeight->setToolTip("Set the Scene Height");
	mSceneWidth = new QSliderAffiche(Qt::Horizontal),mSceneWidth->setToolTip("Set the Scene Width");
	mViewHeight = new QSliderAffiche(Qt::Horizontal), mViewHeight->setToolTip("Set the View Height");
	mViewWidth = new QSliderAffiche(Qt::Horizontal), mViewWidth->setToolTip("Set the View Width");

	//Environment parameters
	mInfectionProbability = new QSliderAffiche(Qt::Horizontal), mInfectionProbability->setToolTip("Set the Infection Probability");
	mAverageVirusStrenght = new QSliderAffiche(Qt::Horizontal), mAverageVirusStrenght->setToolTip("Set the Average Virus Strenght");
	mHumanEnergyDropRate = new QSliderAffiche(Qt::Horizontal), mHumanEnergyDropRate->setToolTip("Set the initial Human Energy Drop Rate");
	mZombieEnergyDropRate = new QSliderAffiche(Qt::Horizontal), mZombieEnergyDropRate->setToolTip("Set the initial Zombie Energy Drop Rate");
	mViewRay = new QSliderAffiche(Qt::Horizontal), mViewRay->setToolTip("Set the view ray in this environment");
	mRotationAngle = new QSliderAffiche(Qt::Horizontal), mRotationAngle->setToolTip("Set the rotation angle");


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
	mEntityCarGBL->addRow(mAverageAgeString,mAverageAge);
	mEntityCarGBL->addRow(mAverageSpeedString, mAverageSpeed);
	mEntityCarGBL->addRow(mReproductionProbabilityString, mReproductionProbability);
	mEntityCarGBL->addRow(mPregnancyDurationString, mPregnancyDuration);
	mEntityCarGBL->addRow(mNewMilitaryProbabilityString, mNewMilitaryProbability);
	mEntityCarGBL->addRow(mWomanProbabilityString, mWomanProbability);
	mEnvironmentCarGBL->addRow(mProbSpeedString, mProbSpeed);

	

	//Environment Parameters
	mEnvironmentCarGBL->addRow(mInfectionProbabilityString,mInfectionProbability);
	mEnvironmentCarGBL->addRow(mAverageVirusStrenghtString, mAverageVirusStrenght);
	mEnvironmentCarGBL->addRow(mAverageVirusResistanceString, mAverageVirusResistance);
	mEnvironmentCarGBL->addRow(mHumanEnergyDropRateString, mHumanEnergyDropRate);
	mEnvironmentCarGBL->addRow(mZombieEnergyDropRateString, mZombieEnergyDropRate);
	mEnvironmentCarGBL->addRow(mViewRayString, mViewRay);
	mEnvironmentCarGBL->addRow(mRotationAngleString, mRotationAngle);


							/*
							   _____ ____  _   _ _   _ ______ _____ _______ _____ ____  _   _  _____ 
							  / ____/ __ \| \ | | \ | |  ____/ ____|__   __|_   _/ __ \| \ | |/ ____|
							 | |   | |  | |  \| |  \| | |__ | |       | |    | || |  | |  \| | (___  
							 | |   | |  | | . ` | . ` |  __|| |       | |    | || |  | | . ` |\___ \ 
							 | |___| |__| | |\  | |\  | |___| |____   | |   _| || |__| | |\  |____) |
							  \_____\____/|_| \_|_| \_|______\_____|  |_|  |_____\____/|_| \_|_____/ 
							*/                                                                   
                                                                         


	//Connect Entity Count to ParamSim Variables
	connect(mZombieCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QParametersTab::updateParameters);
	connect(mHumanCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QParametersTab::updateParameters);
	connect(mWomanCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QParametersTab::updateParameters);
	connect(mMilitaryCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QParametersTab::updateParameters);
	connect(mVirusCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QParametersTab::updateParameters);
	connect(mCityCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QParametersTab::updateParameters);

	//Connect Scene Parameters to ParamSim Variables
	connect(mSceneHeight, &QSlider::valueChanged,this, &QParametersTab::updateParameters);
	connect(mSceneWidth, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mViewHeight, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mViewWidth, &QSlider::valueChanged, this, &QParametersTab::updateParameters);


	//Connect Entity Caracteristics to ParamSim Variables
	connect(mAverageAge, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mNewMilitaryProbability, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mReproductionProbability, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mWomanProbability, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mPregnancyDuration, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mProbSpeed, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	
	//Connect Environment Caracteristics to ParamSim Variables
	connect(mInfectionProbability, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mAverageVirusStrenght, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mAverageVirusResistance, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mHumanEnergyDropRate, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mZombieEnergyDropRate, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mViewRay, &QSlider::valueChanged, this, &QParametersTab::updateParameters);
	connect(mRotationAngle, &QSlider::valueChanged, this, &QParametersTab::updateParameters);


	setLayout(mMainLayout);
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