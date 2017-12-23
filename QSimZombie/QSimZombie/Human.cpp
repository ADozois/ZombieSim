#include "Human.h"
#include "Environnement.h"
#include "Children.h"
#include "Military.h"
#include "Virus.h"
#include "ParamSim.h"
#include "QStatSim.h"
#include <QPainter>



const double Human::mResistanceDeviation{0.2};
const double Human::mDeathAgeDeviation{0.3};
const QColor Human::mHumanColor{ 66, 134, 244 };

//Use to create new humans at the begginning of the simulation
Human::Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age, bool military, bool infected, QGraphicsItem *parent)
	:QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide,parent),
	mAge{age},
	mSpecifier{nullptr},
	mVirus{nullptr},
	mWillBeocmeMilitary{false}
{
	BaseHumanInit();
    if(military)
	{
		CreateMilitary();
	}
	if (infected)
	{
		CreateVirus();
	}
}

//Use to create new baby with no parents (this one should not be very used)
Human::Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, bool becomeMilitary, bool infected, QGraphicsItem *parent)
	:QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide, parent),
	mAge{ 0 },
	mSpecifier{ nullptr },
	mVirus{ nullptr },
	mWillBeocmeMilitary{ becomeMilitary }
{
	BaseHumanInit();
	if (infected)
	{
		CreateVirus();
	}
	CreateChild();
}

//Used to create a new baby from two parents
Human::Human(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, newHumanParameters *humanParameters, QGraphicsItem *parent)
	:QHumanoid(x, y, currentEnvironnemnt, typeOfHumanoide, humanParameters->avrgRunSpeed,humanParameters->avrgWalkSpeed,humanParameters->avrgViewRay, parent),
	mAge{ 0 },
	mSpecifier{ nullptr },
	mVirus{ nullptr },
	mWillBeocmeMilitary{ humanParameters->isMilitary }
{
	BaseHumanInit();
	if (humanParameters->isInfected)
	{
		CreateVirus();
	}
	CreateChild();
}

Human::~Human()
{
	DeleteSpecifier();
	if (mVirus)
	{
		delete mVirus;
		mVirus = nullptr;
	}
	QStatSim::DecNbrHumain();
	QStatSim::DecNbrNomVivant(mName);
	QStatSim::IncNbrNomMort(mName);
}

void Human::advance(int phase, int const index)
{
	if (!phase)
	{
		//On fait le advance du specifier si l'humain à un specifier
		if (mSpecifier)
		{
			HumanSpecifier::returnAdvance resultAdvance= mSpecifier->advance(phase, index);
			if (resultAdvance == HumanSpecifier::returnAdvance::newAdult)
			{
				IsBecomingAdult();
			}
			else if (resultAdvance == HumanSpecifier::returnAdvance::endMilitary)
			{
				DeleteSpecifier();
			}
		}
		else {			
			if (IsDead())
			{
				mEnvironnement->addDeathHumanoid(index);
				becomeZombie();
			}
			else
			{
				//Le zombi mange l'humain
				if (mEnvironnement->getDistanceToClosestZombie(index) <= mEatingRange)
				{
					mEnvironnement->addDeathHumanoid(index);
				}
				else if (mIsTurning) {
					//On est en train de tourner et on continue donc a faire le tournant pré-déterminé
					makeTurn();
				}
				else if(mEnvironnement->getDistanceToClosestZombie(index)<=mViewRaySq){
					//Zombi est visible, court dans le sens inverse					
					QPointF zombiPos = mEnvironnement->getClosestZombiPos(index);
					setDirectionFrom(zombiPos);
					moveInDirection(movementSpeed::run,mEnvironnement->getHumainDensity(index)+1);
				}
				else if (mEnvironnement->getDistanceToclosestHuman(index) <= mEatingRange) {
					//Si très près d'un autre humain, transmission de virus et s'éloigne de lui en marchant
					transmitVirus(index);
					QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
					setDirectionFrom(humanPos);
					moveInDirection(movementSpeed::walk, mEnvironnement->getHumainDensity(index) + 1);
				}
				else if (mEnvironnement->getDistanceToclosestHuman(index) <= mViewRaySq) {
					//Si humain visible, marche vers lui
					QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
					setDirectionTo(humanPos);
					moveInDirection(movementSpeed::walk, mEnvironnement->getHumainDensity(index) + 1);
				}
				else {
					//Si humain et zombi trop loin pour les voir, marche dans la direction qu'il allait déjà
					moveInDirection(movementSpeed::walk, mEnvironnement->getHumainDensity(index) + 1);
				}
				//L<humain viellit d'un tic (mois)
				++mAge;
			}

		}
	}
}

void Human::advance(int phase)
{
	advance(phase, 0);
}


bool Human::IsDead()
{
	if (mAge == mDeathAge) {
		return true;
	}
	return false;
}


int Human::Age()
{
	return mAge;
}

int Human::DeathAge()
{
	return mDeathAge;
}

qreal Human::VirusResistance()
{
	return mVirusResistance;
}

void Human::transmitVirus(int const index)
{
	Human * closestHuman = mEnvironnement->getClosestHuman(index);
	if (VirusTransmission() && !closestHuman->isInfected())
	{
		if (closestHuman->VirusResistance() < this->mVirus->Strenght())
		{
			closestHuman->CreateVirus(this->mVirus->Strenght());
		}

	}

}

void Human::CreateVirus(double fatherVirusStrenght)
{
	if (!mVirus)
	{
		//On détermine combien de tic le virus enlèvera à l'humain
		//mVirusKillingSpeed = new RandomIntUnif(1, this->mDeathAge - this->mAge-1);

		mDeathAge -= RandomIntUnif::Generate(1, this->mDeathAge - this->mAge + 1);
		mVirus = new Virus(fatherVirusStrenght);
	}
}

void Human::CreateVirus()
{
	if (!mVirus)
	{
		//On détermine combien de tic le virus enlèvera à l'humain
		//mVirusKillingSpeed = new RandomIntUnif(1, this->mDeathAge - this->mAge - 1);
		mDeathAge -= RandomIntUnif::Generate(1, this->mDeathAge - this->mAge + 1);
		mVirus = new Virus();
	}
}

bool Human::VirusTransmission()
{
	if (mVirus)
	{
		return true;
	}
	return false;
}

void Human::MilitaryPainter(QPainter * painter)
{
	Military * military = dynamic_cast<Military*>(mSpecifier);
	if (military)
	{
		mBrushColor = QColor(146, 255, 121);
		mPenColor = QColor(146, 255, 121);
	}
}

void Human::ChildrenPainter(QPainter * painter)
{
	Children * child = dynamic_cast<Children*>(mSpecifier);
	if (child)
	{
		mBrushColor = QColor(247, 224, 76);
		mPenColor = QColor(247, 224, 76);
	}
}

void Human::InfectedPainter(QPainter * painter)
{
	if (mVirus)
	{
		mPenColor = Qt::black;
	}
}

void Human::DeleteSpecifier()
{
	if (mSpecifier)
	{
		delete[] mSpecifier;
		mSpecifier = nullptr;
	}
}

void Human::BaseHumanInit()
{
	mBrushColor = mHumanColor;
	mPenColor = mHumanColor;
	mVirusResistance = RandomNorm::Generate(ParamSim::VirusResistance(), ParamSim::VirusResistance()*mResistanceDeviation);
	mDeathAge = ceil(RandomNorm::Generate(ParamSim::MeanAge(), ParamSim::MeanAge()*mResistanceDeviation));
	if (mDeathAge < mAge)
	{
		mDeathAge = mAge + RandomIntUnif::Generate(0, ceil(ParamSim::MeanAge()*mResistanceDeviation));
	}
	QStatSim::IncNbrHumain();
	QStatSim::IncNbrNomVivant(mName);
}

void Human::BaseHumanInit(newHumanParameters *humanParameters) 
{
	mBrushColor = mHumanColor;
	mPenColor = mHumanColor;
	mVirusResistance =  abs(RandomNorm::Generate(humanParameters->avrgVirusResistance, humanParameters->avrgVirusResistance*mResistanceDeviation));
	mDeathAge = abs(ceil(RandomNorm::Generate(humanParameters->avrgDeathAge, humanParameters->avrgDeathAge*mResistanceDeviation)));
	QStatSim::IncNbrHumain();
	QStatSim::IncNbrNomVivant(mName);

}

void Human::CreateMilitary()
{
	if (mSpecifier)
	{
		throw std::exception("Le pointeur est déjà utilisé par une autre instance");
	}
	else
	{
		mSpecifier = new Military(this);
	}
}



void Human::CreateChild()
{
	if (mSpecifier)
	{
		throw std::exception("Le pointeur est déjà utilisé par une autre instance");
	}
	else
	{
		mSpecifier = new Children(nullptr,this);
	}
}

void Human::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (mSpecifier)
	{
		MilitaryPainter(painter);
		ChildrenPainter(painter);
	}
	else
	{
		painter->setBrush(mBrushColor);
	}
	InfectedPainter(painter);
	InitializeVisual(painter);
}


void Human::becomeZombie() {

	if (mVirus)
	{
		//Create the new zombi where the human was
		Zombie * newZombie = new Zombie(pos().x(), pos().y(), mEnvironnement, humanoideType::zombi);
		mEnvironnement->scene()->addItem(newZombie);
	}
}

void Human::IsBecomingAdult()
{
	DeleteSpecifier();
	if (mWillBeocmeMilitary)
	{
		CreateMilitary();
		mWillBeocmeMilitary = false;
	}
}

void Human::IsRetiring()
{
	if (mAge >= Military::AgeEnd())
	{
		DeleteSpecifier();
	}
}
