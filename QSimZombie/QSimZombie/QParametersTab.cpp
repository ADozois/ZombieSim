#include "QParametersTab.h"
#include "ParamSim.h"


								//QStrings for parameters
//Entity Quantities
const QString QParametersTab::mZombieCountString{ "Zombie Count" };
const QString QParametersTab::mHumanCountString{ "Human Count" };
const QString QParametersTab::mWomanCountString{ "Woman Count" };
const QString QParametersTab::mMilitaryCountString{ "Military Count" };
const QString QParametersTab::mVirusCountString{ "Virus Count" };

//Entity Caracteristics
const QString QParametersTab::mAverageAgeString{"Average Age"};
const QString QParametersTab::mAverageSpeedString{"Average Speed"};
const QString QParametersTab::mAverageVirusResistanceString{"Average Virus Resistance"};
const QString QParametersTab::mReproductionProbabilityString{"Reproduction Probability"};
const QString QParametersTab::mPregnancyDurationString{"Pregnancy Duration"};
const QString QParametersTab::mNewMilitaryProbabilityString{"New Military Probability"};
const QString QParametersTab::mWomanProbabilityString{"Woman Probability"};
const QString QParametersTab::mHumanEnergyDropRateString{"Human Energy Drop Rate"};
const QString QParametersTab::mZombieEnergyDropRateString{"Zombie Energy Drop Rate"};

//Scene Parameter Strings
const QString QParametersTab::mSceneHeightString{ "Scene Height" };
const QString QParametersTab::mSceneWidthString{ "Scene Width" };
const QString QParametersTab::mViewHeightString{ "View Height" };
const QString QParametersTab::mViewWidthString{ "View Width" };

//Environment Parameter Strings
const QString QParametersTab::mInfectionProbabilityString{ "Infection Probability" };
const QString QParametersTab::mAverageVirusStrenghtString{ "Average Virus Strenght" };

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
	
	//Entity Caracteristics
	mAverageAge = new QSlider(Qt::Horizontal),mAverageAge->setToolTip("Set the initial Average Age");
	mAverageSpeed = new QSlider(Qt::Horizontal),mAverageSpeed->setToolTip("Set the initial Average Speed");
	mAverageVirusResistance =  new QSlider(Qt::Horizontal), mAverageVirusResistance->setToolTip("Set the initial Average Virus Resistance");
	mReproductionProbability = new QSlider(Qt::Horizontal), mReproductionProbability->setToolTip("Set the initial Reproduction Probability");
	mPregnancyDuration = new QSlider(Qt::Horizontal), mPregnancyDuration->setToolTip("Set the initial Pregnancy Duration");
	mNewMilitaryProbability = new QSlider(Qt::Horizontal), mNewMilitaryProbability->setToolTip("Set the probability of a New Military");
	mWomanProbability = new QSlider(Qt::Horizontal),mWomanProbability->setToolTip("Set the probability of a woman");
	mHumanEnergyDropRate = new QSlider(Qt::Horizontal), mHumanEnergyDropRate->setToolTip("Set the initial Human Energy Drop Rate");
	mZombieEnergyDropRate = new QSlider(Qt::Horizontal), mZombieEnergyDropRate->setToolTip("Set the initial Zombie Energy Drop Rate");

	//Scene Parameters
	mSceneHeight = new QSlider(Qt::Horizontal),mSceneHeight->setToolTip("Set the Scene Height");
	mSceneWidth = new QSlider(Qt::Horizontal),mSceneWidth->setToolTip("Set the Scene Width");
	mViewHeight = new QSlider(Qt::Horizontal), mViewHeight->setToolTip("Set the View Height");
	mViewWidth = new QSlider(Qt::Horizontal), mViewWidth->setToolTip("Set the View Width");

	//Environment parameters
	mInfectionProbability = new QSlider(Qt::Horizontal), mInfectionProbability->setToolTip("Set the Infection Probability");
	mAverageVirusStrenght = new QSlider(Qt::Horizontal), mAverageVirusStrenght->setToolTip("Set the Average Virus Strenght");

										//AddRows to formlayouts
	//Entity Quantities
	mEntityQtyGBL->addRow(mZombieCountString, mZombieCount);
	mEntityQtyGBL->addRow(mHumanCountString, mHumanCount);
	mEntityQtyGBL->addRow(mWomanCountString, mWomanCount);
	mEntityQtyGBL->addRow(mMilitaryCountString, mMilitaryCount);
	mEntityQtyGBL->addRow(mVirusCountString, mVirusCount);

	//Entity Caracteristics
	mEntityCarGBL->addRow(mAverageAgeString,mAverageAge);
	mEntityCarGBL->addRow(mAverageSpeedString, mAverageSpeed);
	
	mEntityCarGBL->addRow(mReproductionProbabilityString, mReproductionProbability);
	mEntityCarGBL->addRow(mPregnancyDurationString, mPregnancyDuration);
	mEntityCarGBL->addRow(mNewMilitaryProbabilityString, mNewMilitaryProbability);
	mEntityCarGBL->addRow(mWomanProbabilityString, mWomanProbability);
	

	//Scene Parameters
	mSceneParamGBL->addRow(mSceneHeightString, mSceneHeight);
	mSceneParamGBL->addRow(mSceneWidthString, mSceneWidth);
	mSceneParamGBL->addRow(mViewHeightString, mViewHeight);
	mSceneParamGBL->addRow(mViewWidthString, mViewWidth);

	//Environment Parameters
	mEnvironmentCarGBL->addRow(mInfectionProbabilityString,mInfectionProbability);
	mEnvironmentCarGBL->addRow(mAverageVirusStrenghtString, mAverageVirusStrenght);
	mEnvironmentCarGBL->addRow(mAverageVirusResistanceString, mAverageVirusResistance);
	mEnvironmentCarGBL->addRow(mHumanEnergyDropRateString, mHumanEnergyDropRate);
	mEnvironmentCarGBL->addRow(mZombieEnergyDropRateString, mZombieEnergyDropRate);

	//connect(mAverageAge);
	






	setLayout(mMainLayout);
}
