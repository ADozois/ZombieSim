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

class QParametersTab : public QWidget {

	Q_OBJECT

public:
	QParametersTab(QWidget *parent = Q_NULLPTR);

protected:

	//Layouts
	QHBoxLayout *mMainLayout;
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
	QSpinBox *mZombieCount;
	QSpinBox *mHumanCount;
	QSpinBox *mWomanCount;
	QSpinBox *mMilitaryCount;
	QSpinBox *mVirusCount;
	QSpinBox *mCityCount;
	
	//Entity Caracteristics
	QSlider *mAverageAge;
	QSlider *mAverageSpeed;
	
	QSlider *mReproductionProbability;
	QSlider *mPregnancyDuration;
	QSlider *mNewMilitaryProbability;
	QSlider *mWomanProbability;

	//Scene Parameters
	QSlider *mSceneHeight;
	QSlider *mSceneWidth;
	QSlider *mViewHeight;
	QSlider *mViewWidth;

	//Environment Caracteristics
	QSlider *mInfectionProbability;
	QSlider *mAverageVirusStrenght;
	QSlider *mAverageVirusResistance;
	QSlider *mHumanEnergyDropRate;
	QSlider *mZombieEnergyDropRate;

									//Labels
	//Entity count labels
	QLabel *mZombieCountLabel;
	QLabel *mHumanCountLabel;
	QLabel *mWomanCountLabel;
	QLabel *mMilitaryCountLabel;
	QLabel *mVirusCountLabel;

									//String
	//Entity Quantity QString
	static const QString mZombieCountString;
	static const QString mHumanCountString;
	static const QString mWomanCountString;
	static const QString mMilitaryCountString;
	static const QString mVirusCountString;

	//Entity Caracteristics
	static const QString mAverageAgeString;
	static const QString mAverageSpeedString;

	static const QString mReproductionProbabilityString;
	static const QString mPregnancyDurationString;
	static const QString mNewMilitaryProbabilityString;
	static const QString mWomanProbabilityString;
	
	//Scene Parameters
	static const QString mSceneHeightString;
	static const QString mSceneWidthString;
	static const QString mViewHeightString;
	static const QString mViewWidthString;

	//Environment Parameters
	static const QString mInfectionProbabilityString;
	static const QString mAverageVirusStrenghtString;
	static const QString mHumanEnergyDropRateString;
	static const QString mZombieEnergyDropRateString;
	static const QString mAverageVirusResistanceString;
};





#endif //Q_PARAMETERS_TAB_H