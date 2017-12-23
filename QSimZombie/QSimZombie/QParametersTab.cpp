#include "QParametersTab.h"
#include "ParamSim.h"
#include "QMessageBox"


//QStrings for parameters
//Entity Quantities
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
//
////Scene Parameter Strings
//const QString QParametersTab::mSceneHeightString{ "Scene Height" };
//const QString QParametersTab::mSceneWidthString{ "Scene Width" };
//const QString QParametersTab::mViewHeightString{ "View Height" };
//const QString QParametersTab::mViewWidthString{ "View Width" };

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
	//add about button
	mAboutButton = new QPushButton("About this Simulation");
	connect(mAboutButton, &QPushButton::clicked, this, &QParametersTab::showAboutSimulation);
	//mValidate->set
	mMainLayout2->addLayout(mValidateLayout);

	mValidateLayout->addStretch();
	mValidateLayout->addWidget(mValidateButton);
	mValidateLayout->addStretch();




	mRightLayout->addWidget(mEnvironmentCarGB);
	mRightLayout->addWidget(mAboutButton);

	//Each GroupBox has its Layout
	mEntityQtyGB->setLayout(mEntityQtyGBL);
	mEntityCarGB->setLayout(mEntityCarGBL);
	mEnvironmentCarGB->setLayout(mEnvironmentCarGBL);
	//mSceneParamGB->setLayout(mSceneParamGBL);

	//Parameter Spinboxes and Sliders
	////Entity Count
	//mZombieCount = new QSpinBox;
	//mZombieCount->setToolTip("Set the number of roaming zombies");
	//mZombieCount->setRange(entityMinimum, entityMaximum);

	mHumanCount = new QSpinBox;
	mHumanCount->setToolTip("Set the initial number of humans");
	mHumanCount->setRange(entityMinimum, entityMaximum);
	mHumanCount->setValue(100);

	mWomanCount = new QSpinBox;
	mWomanCount->setToolTip("Set the probability a human will be a women");
	mWomanCount->setRange(entityMinimumRatio, entityMaximumRatio); //Faudra g�rer que mWomanCount + mMilitaryCount <= mHumanCount
	mWomanCount->setValue(50);

	mMilitaryCount = new QSpinBox;
	mMilitaryCount->setToolTip("Set the probability a human will be military");
	mMilitaryCount->setRange(entityMinimumRatio, entityMaximumRatio);
	mMilitaryCount->setValue(25);

	mVirusCount = new QSpinBox;
	mVirusCount->setToolTip("Set the probability a human will be infected");
	mVirusCount->setRange(entityMinimumRatio, entityMaximumRatio);
	mVirusCount->setValue(10);

	mCityCount = new QSpinBox;
	mCityCount->setToolTip("Set the initial nomber of cities");
	mCityCount->setRange(entityMinimumTown, entityMaximumTown);
	mCityCount->setValue(5);


	//Entity Caracteristics
	mAverageAge = new QSliderAffiche(Qt::Horizontal), mAverageAge->setToolTip("Set the initial Average Age");
	mAverageAge->setRange(10, 80);
	mAverageAge->setValue(40);

	mAverageSpeed = new QSliderAffiche(Qt::Horizontal), mAverageSpeed->setToolTip("Set the initial Average Speed");
	mAverageSpeed->setRange(1, 100);
	mAverageSpeed->setValue(50);

	mAverageVirusResistance = new QSliderAffiche(Qt::Horizontal), mAverageVirusResistance->setToolTip("Set the initial Average Virus Resistance");
	mAverageVirusResistance->setRange(10, 100);
	mAverageVirusResistance->setValue(50);

	mReproductionProbability = new QSliderAffiche(Qt::Horizontal), mReproductionProbability->setToolTip("Set the initial Reproduction Probability");
	mReproductionProbability->setRange(20, 80);
	mReproductionProbability->setValue(50);

	mNewMilitaryProbability = new QSliderAffiche(Qt::Horizontal), mNewMilitaryProbability->setToolTip("Set the probability of a New Military");
	mNewMilitaryProbability->setRange(10, 90);
	mNewMilitaryProbability->setValue(20);

	/*mProbSpeed = new QSliderAffiche(Qt::Horizontal), mProbSpeed->setToolTip("Set the speed variable");
	mProbSpeed->setRange(20, 80);*/

	////Scene Parameters
	//mSceneHeight = new QSliderAffiche(Qt::Horizontal), mSceneHeight->setToolTip("Set the Scene Height");
	//mSceneHeight->setRange(500, 5000);
	//mSceneHeight->setValue(1000);

	//mSceneWidth = new QSliderAffiche(Qt::Horizontal), mSceneWidth->setToolTip("Set the Scene Width");
	//mSceneWidth->setRange(500, 5000);
	//mSceneWidth->setValue(1000);

	//mViewHeight = new QSliderAffiche(Qt::Horizontal), mViewHeight->setToolTip("Set the View Height");
	//mViewHeight->setRange(500, 5000);
	//mViewHeight->setValue(1000);

	//mViewWidth = new QSliderAffiche(Qt::Horizontal), mViewWidth->setToolTip("Set the View Width");
	//mViewWidth->setRange(500, 5000);
	//mViewWidth->setValue(1000);

	//Environment parameters
	mInfectionProbability = new QSliderAffiche(Qt::Horizontal), mInfectionProbability->setToolTip("Set the Infection Probability");
	mInfectionProbability->setRange(10, 90);
	mInfectionProbability->setValue(10);

	mAverageVirusStrenght = new QSliderAffiche(Qt::Horizontal), mAverageVirusStrenght->setToolTip("Set the Average Virus Strenght");
	mAverageVirusStrenght->setRange(10, 100);
	mAverageVirusStrenght->setValue(30);


	//mHumanEnergyDropRate = new QSliderAffiche(Qt::Horizontal), mHumanEnergyDropRate->setToolTip("Set the initial Human Energy Drop Rate");
	//mHumanEnergyDropRate->setRange(10, 80);
	//mZombieEnergyDropRate = new QSliderAffiche(Qt::Horizontal), mZombieEnergyDropRate->setToolTip("Set the initial Zombie Energy Drop Rate");
	//mZombieEnergyDropRate->setRange(10, 80);

	mViewRay = new QSliderAffiche(Qt::Horizontal), mViewRay->setToolTip("Set the average view ray in this environment");
	mViewRay->setRange(30, 70);
	mViewRay->setValue(50);

	mRotationAngle = new QSliderAffiche(Qt::Horizontal), mRotationAngle->setToolTip("Set the rotation angle");
	mRotationAngle->setRange(10, 180);
	mRotationAngle->setValue(90);


	//AddRows to formlayouts
	//Entity Quantities
	mEntityQtyGBL->addRow(mHumanCountString, mHumanCount);
	mEntityQtyGBL->addRow(mWomanCountString, mWomanCount);
	mEntityQtyGBL->addRow(mMilitaryCountString, mMilitaryCount);
	mEntityQtyGBL->addRow(mVirusCountString, mVirusCount);
	mEntityQtyGBL->addRow(mCityCountString, mCityCount);

	//Scene Parameters
	/*mSceneParamGBL->addRow(mSceneHeightString, mSceneHeight);
	mSceneParamGBL->addRow(mSceneWidthString, mSceneWidth);
	mSceneParamGBL->addRow(mViewHeightString, mViewHeight);
	mSceneParamGBL->addRow(mViewWidthString, mViewWidth);*/

	//Entity Caracteristics
	mEntityCarGBL->addRow(mAverageAgeString, mAverageAge);
	mEntityCarGBL->addRow(mAverageSpeedString, mAverageSpeed);
	mEntityCarGBL->addRow(mReproductionProbabilityString, mReproductionProbability);
	mEntityCarGBL->addRow(mNewMilitaryProbabilityString, mNewMilitaryProbability);
	/*mEnvironmentCarGBL->addRow(mProbSpeedString, mProbSpeed);*/



	//Environment Parameters
	mEnvironmentCarGBL->addRow(mInfectionProbabilityString, mInfectionProbability);
	mEnvironmentCarGBL->addRow(mAverageVirusStrenghtString, mAverageVirusStrenght);
	//mEnvironmentCarGBL->addRow(mAverageVirusResistanceString, mAverageVirusResistance);
	//mEnvironmentCarGBL->addRow(mHumanEnergyDropRateString, mHumanEnergyDropRate);
	//mEnvironmentCarGBL->addRow(mZombieEnergyDropRateString, mZombieEnergyDropRate);
	mEnvironmentCarGBL->addRow(mViewRayString, mViewRay);
	mEnvironmentCarGBL->addRow(mRotationAngleString, mRotationAngle);

	setLayout(mMainLayout2);
}


void QParametersTab::updateParameters()
{

	ParamSim::setProbWoman(mWomanCount->value());
	ParamSim::setNbrMilitary(mMilitaryCount->value());
	ParamSim::setNbrVirus(mVirusCount->value());
	ParamSim::setNbrHuman(mHumanCount->value());
	ParamSim::setNbrCity(mCityCount->value());
	ParamSim::setMeanAge(mAverageAge->value() *mTimeConvert);
	ParamSim::setViewRay(mViewRay->value());
	ParamSim::setRotationAngle(mRotationAngle->value());
	ParamSim::setVirusResistance(mAverageVirusResistance->value());
	ParamSim::setMeanVirusForce(mAverageVirusStrenght->value());
	ParamSim::setProbNewMilitary(mNewMilitaryProbability->value());
	ParamSim::setProbReproduction(mReproductionProbability->value());
	ParamSim::setProbInfection(mInfectionProbability->value());
	ParamSim::setProbSpeed(mAverageSpeed->value());

}

void QParametersTab::showAboutSimulation()
{
	QString titreSimulationWindow{ "À propos de ZombiSimulation" };
	QString messageAboutSim{ R"-%-(Cette simulation permet de voir les effets d'un virus zombitisant sur une population.
Dans la simulation, les hommes sont en bleu, les femmes sont en rose, les militaires sont en vert, les enfants sont en jaune et les zombis sont en noir.
Une personne infectée aura un contour noir.

Ce programme est réalisé par:
	-Antoine Dozois
	-Guillaume Chabot-Nobert
	-Olivier Carrier

Dans le cadre du cours:
	-GPA789 - Analyse et conception orientées objet
	-Laboratoire 3

Version 1.0)-%-" };

	QMessageBox::about(this, titreSimulationWindow, messageAboutSim);
}