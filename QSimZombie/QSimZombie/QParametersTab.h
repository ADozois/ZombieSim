#ifndef Q_PARAMETERS_TAB_H
#define Q_PARAMETERS_TAB_H
#include <QtWidgets/QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include "QSliderAffiche.h"
#include <QPushbutton>

class ParamSim;

class QParametersTab : public QWidget {

	Q_OBJECT

public:
	QParametersTab(QWidget *parent = Q_NULLPTR);
	
	QPushButton *getValidateButton() { return mValidateButton; }


<<<<<<< HEAD
public slots:

	
	void updateParameters();
=======
	QPushButton *getValidateButton() { return mValidateButton; }


public slots:

	void updateParameters();

protected slots:
	void showAboutSimulation();
>>>>>>> master

protected:


<<<<<<< HEAD
	QPushButton *mValidateButton;
=======
	QPushButton * mValidateButton;
	QPushButton * mAboutButton;
>>>>>>> master

	//Layouts
	QHBoxLayout *mMainLayout;
	QVBoxLayout *mMainLayout2;
	QHBoxLayout *mValidateLayout;
	QVBoxLayout *mLeftLayout;
	QVBoxLayout *mRightLayout;

	//Groupbox
	QGroupBox *mEntityQtyGB;
	QGroupBox *mSceneParamGB;
	QGroupBox *mEntityCarGB;
	QGroupBox *mEnvironmentCarGB;

	//GroupboxLayouts and layoutseparator
	QFormLayout *mEntityQtyGBL;
	QFormLayout *mEntityCarGBL;
	QFormLayout *mEnvironmentCarGBL;
	QFormLayout *mSceneParamGBL;


	// PARAMETER BUTTONS/SLIDERS

	//Entity quantitites
<<<<<<< HEAD
	QSpinBox *mZombieCount;
=======
>>>>>>> master
	QSpinBox *mHumanCount;
	QSpinBox *mWomanCount;
	QSpinBox *mMilitaryCount;
	QSpinBox *mVirusCount;
	QSpinBox *mCityCount;

<<<<<<< HEAD
	
=======

>>>>>>> master
	//Scene Parameters
	QSliderAffiche *mSceneHeight;
	QSliderAffiche *mSceneWidth;
	QSliderAffiche *mViewHeight;
	QSliderAffiche *mViewWidth;
<<<<<<< HEAD

	//Entity Caracteristics
	QSliderAffiche *mAverageAge;
	QSliderAffiche *mAverageSpeed;
	QSliderAffiche *mReproductionProbability;
	QSliderAffiche *mPregnancyDuration;
	QSliderAffiche *mNewMilitaryProbability;
	QSliderAffiche *mWomanProbability;
	QSliderAffiche *mProbSpeed;

	
=======

	//Entity Caracteristics
	QSliderAffiche *mAverageAge;
	QSliderAffiche *mAverageSpeed;
	QSliderAffiche *mReproductionProbability;
	QSliderAffiche *mPregnancyDuration;
	QSliderAffiche *mNewMilitaryProbability;
	QSliderAffiche *mWomanProbability;
	QSliderAffiche *mProbSpeed;


>>>>>>> master

	//Environment Caracteristics
	QSliderAffiche *mInfectionProbability;
	QSliderAffiche *mAverageVirusStrenght;
	QSliderAffiche *mAverageVirusResistance;
	QSliderAffiche *mHumanEnergyDropRate;
	QSliderAffiche *mZombieEnergyDropRate;
	QSliderAffiche *mViewRay;
	QSliderAffiche *mRotationAngle;

	//Labels
	//Entity count labels
	QLabel *mHumanCountLabel;
	QLabel *mWomanCountLabel;
	QLabel *mMilitaryCountLabel;
	QLabel *mVirusCountLabel;

	static const int entityMinimum{ 10 };
	static const int entityMaximum{ 500 };
	static const int mTimeConvert{ 12 };
	static const int entityMaximumRatio{ 90 };
	static const int entityMinimumRatio{ 10 };
	static const int entityMinimumTown{ 1 };
	static const int entityMaximumTown{ 50 };


	//String
	//Entity Quantity QString
	static const QString mHumanCountString;
	static const QString mWomanCountString;
	static const QString mMilitaryCountString;
	static const QString mVirusCountString;
	static const QString mCityCountString;

	//Scene Parameters
	static const QString mSceneHeightString;
	static const QString mSceneWidthString;
	static const QString mViewHeightString;
	static const QString mViewWidthString;

	//Entity Caracteristics
	static const QString mAverageAgeString;
	static const QString mAverageSpeedString;
	static const QString mReproductionProbabilityString;
	static const QString mPregnancyDurationString;
	static const QString mNewMilitaryProbabilityString;
	static const QString mWomanProbabilityString;
	static const QString mProbSpeedString;

	//Environment Parameters
	static const QString mInfectionProbabilityString;
	static const QString mAverageVirusStrenghtString;
	static const QString mHumanEnergyDropRateString;
	static const QString mZombieEnergyDropRateString;
	static const QString mAverageVirusResistanceString;
	static const QString mViewRayString;
	static const QString mRotationAngleString;
};





#endif //Q_PARAMETERS_TAB_H