#ifndef Q_STAT_SIM_H
#define Q_STAT_SIM_H

#include <map>
#include <QString>
#include <vector>

class ParamSim;

class QStatSim
{
public:
	QStatSim() = default;
	QStatSim(ParamSim * params);
	~QStatSim();

	static void SetNbrZombie(int value);
	static void SetNbrHumain(int value);
	static void SetNbrHomme(int value);
	static void SetNbrFemme(int value);
	static void SetNbrEnfant(int value);
	static void SetNbrMilitaire(int value);
	static void SetNbrMort(int value);
	static void SetNbrNomMort(std::map<QString, int> value);
	static void SetNbrNomVivant(std::map<QString, int> value);
	static void SetPopEvol(std::vector<int> value);

	static int NbrZombie() { return mNbrZombie; };
	static int NbrHumain() { return mNbrHumain; };
	static int NbrHomme() { return mNbrHumain - mNbrFemme; };
	static int NbrFemme() { return mNbrFemme; };
	static int NbrEnfant() { return mNbrEnfant; };
	static int NbrMilitaire() { return mNbrMilitaire; };
	static int NbrMort() { return mNbrMort; };
	static std::map<QString, int> NbrNomMort() { return mNbrNomMort; };
	static std::map<QString, int> NbrNomVivant() { return mNbrNomVivant; };
	static std::map<QString, int> NbrInstance();
	static std::vector<int> PopEvol() { return mPopEvol; };

	static void IncNbrZombie();
	static void IncNbrHumain();
	static void IncNbrHomme();
	static void IncNbrFemme();
	static void IncNbrEnfant();
	static void IncNbrMilitaire();
	static void IncNbrMort();
	static void IncNbrNomMort(QString name);
	static void IncNbrNomVivant(QString name);

	static void DecNbrZombie();
	static void DecNbrHumain();
	static void DecNbrHomme();
	static void DecNbrFemme();
	static void DecNbrEnfant();
	static void DecNbrMilitaire();
	static void DecNbrMort();
	static void DecNbrNomMort(QString name);
	static void DecNbrNomVivant(QString name);

	static void UpdatePop();
	static qreal PourcentageZombie(void);
	static qreal PourcentageHumain(void);
	static qreal PourcentageHomme(void);
	static qreal PourcentageFemme(void);
	static qreal PourcentageMilitaire(void);

private:
	static int mNbrZombie;
	static int mNbrHumain;
	static int mNbrHomme;
	static int mNbrFemme;
	static int mNbrMilitaire;
	static int mNbrEnfant;
	static int mNbrMort;
	static std::map<QString, int> mNbrNomMort;
	static std::map<QString, int> mNbrNomVivant;
	static std::vector<int> mPopEvol;
};


#endif // !Q_STAT_SIM_H


