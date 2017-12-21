#include "QStatSim.h"
#include "ParamSim.h"


int QStatSim::mNbrZombie{ 0 };
int QStatSim::mNbrHumain{ 0 };
int QStatSim::mNbrHomme{ 0 };
int QStatSim::mNbrFemme{ 0 };
int QStatSim::mNbrEnfant{ 0 };
int QStatSim::mNbrMilitaire{ 0 };
int QStatSim::mNbrMort{ 0 };
std::map<QString, int> QStatSim::mNbrNomMort{ { "Antoine", 0 }, { "Guillaume", 0 }, { "Olivier", 0 } };
std::map<QString, int> QStatSim::mNbrNomVivant{ { "Antoine", 0 },{ "Guillaume", 0 },{ "Olivier", 0 } };
std::vector<int> QStatSim::mPopEvol{};


QStatSim::QStatSim(ParamSim * params)
{
	mNbrHumain = params->NbrHuman();
}


QStatSim::~QStatSim()
{

}

void QStatSim::SetNbrZombie(int value)
{
	if (value > 0)
	{
		mNbrZombie = value;
	}
}

void QStatSim::SetNbrHumain(int value)
{
	if (value > 0)
	{
		mNbrHumain = value;
	}
}

void QStatSim::SetNbrHomme(int value)
{
	if (value > 0)
	{
		mNbrHomme = value;
	}
}

void QStatSim::SetNbrFemme(int value)
{
	if (value > 0)
	{
		mNbrFemme = value;
	}
}

void QStatSim::SetNbrEnfant(int value)
{
	if (value > 0)
	{
		mNbrEnfant = value;
	}
}

void QStatSim::SetNbrMilitaire(int value)
{
	if (value > 0)
	{
		mNbrMilitaire = value;
	}
}

void QStatSim::SetNbrMort(int value)
{
	if (value > 0)
	{
		mNbrMort = value;
	}
}

void QStatSim::SetNbrNomMort(std::map<QString, int> value) {
	mNbrNomMort = value;
}
void QStatSim::SetNbrNomVivant(std::map<QString, int> value) {
	mNbrNomMort = value;
}
void QStatSim::SetPopEvol(std::vector<int> value) {
	mPopEvol = value;
};

std::map<QString, int> QStatSim::NbrInstance()
{
	return std::map<QString, int>{ {"Militaire", mNbrMilitaire}, { "Homme", NbrHomme() }, { "Femme", mNbrFemme }, { "Children", mNbrEnfant }, { "Zombie", mNbrZombie } };
}

void QStatSim::IncNbrZombie()
{
	mNbrZombie++;
}

void QStatSim::IncNbrHumain()
{
	mNbrHumain++;
}

void QStatSim::IncNbrHomme()
{
	mNbrHomme++;
}

void QStatSim::IncNbrFemme()
{
	mNbrFemme++;
}

void QStatSim::IncNbrEnfant()
{
	mNbrEnfant++;
}

void QStatSim::IncNbrMilitaire()
{
	mNbrMilitaire++;
}

void QStatSim::IncNbrMort()
{
	mNbrMort++;
}

void QStatSim::IncNbrNomMort(QString name)
{
	int t = mNbrNomMort.find(name)->second;
}

void QStatSim::IncNbrNomVivant(QString name)
{
	mNbrNomVivant.find(name)->second++;
}

void QStatSim::DecNbrZombie()
{
	mNbrZombie--;
}

void QStatSim::DecNbrHumain()
{
	mNbrHumain--;
}

void QStatSim::DecNbrHomme()
{
	mNbrHomme--;
}

void QStatSim::DecNbrFemme()
{
	mNbrFemme--;
}

void QStatSim::DecNbrEnfant()
{
	mNbrEnfant--;
}

void QStatSim::DecNbrMilitaire()
{
	mNbrMilitaire--;
}

void QStatSim::DecNbrMort()
{
	mNbrMort--;
}

void QStatSim::DecNbrNomMort(QString name)
{
	mNbrNomMort.find(name)->second--;
}

void QStatSim::DecNbrNomVivant(QString name)
{
	mNbrNomVivant.find(name)->second--;
}

void QStatSim::UpdatePop()
{
	mPopEvol.push_back(mNbrHumain);
}

qreal QStatSim::PourcentageZombie(void)
{
	return mNbrZombie/(mNbrZombie+mNbrHumain);
}

qreal QStatSim::PourcentageHumain(void)
{
	return 1 - PourcentageZombie();
}

qreal QStatSim::PourcentageHomme(void)
{
	return 1 - PourcentageFemme();
}

qreal QStatSim::PourcentageFemme(void)
{
	return mNbrFemme/mNbrHumain;
}

qreal QStatSim::PourcentageMilitaire(void)
{
	return mNbrMilitaire/mNbrHumain;
}
