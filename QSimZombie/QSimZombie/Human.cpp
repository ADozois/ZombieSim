#include "Human.h"
#include "Environnement.h"
#include "Children.h"
#include "Military.h"
#include "Virus.h"
#include "ParamSim.h"
#include "QStatSim.h"
#include <QPainter>

RandomNorm * Human::mResistanceGenerator{nullptr};
const double Human::mResistanceMean{50.0};
const double Human::mResistanceDeviation{0.2};
RandomNorm * Human::mDeathAgeGenerator{nullptr};
const double Human::mDeathAgeMean{80.0};
const double Human::mDeathAgeDeviation{0.3};
const QColor Human::mHumanColor{ 241, 140, 135 };

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
			mSpecifier->advance(phase, index);
		}
		else {			
			if (IsDead())
			{
				mEnvironnement->addDeathHumanoid(index);
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
					mMovementDirection = mTurningDirection[mTurningAtPosition];
					++mTurningAtPosition;
					moveInDirection(movementSpeed::run);
					if (mTurningAtPosition > mNumberOfTurningDirection)
					{
						mIsTurning = false;
					}
				}
				else if(mEnvironnement->getDistanceToClosestZombie(index)<=mViewRaySq){
					//Zombi est visible, court dans le sens inverse					
					QPointF zombiPos = mEnvironnement->getClosestZombiPos(index);
					setDirectionFrom(zombiPos);
					moveInDirection(movementSpeed::run);
				}
				else if (mEnvironnement->getDistanceToclosestHuman(index) <= mEatingRange) {
					//Si très près d'un autre humain, transmission de virus et s'éloigne de lui en marchant
					VirusTransmission();
					QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
					setDirectionFrom(humanPos);
					moveInDirection(movementSpeed::walk);
				}
				else if (mEnvironnement->getDistanceToclosestHuman(index) <= mViewRaySq) {
					//Si humain visible, marche vers lui
					QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
					setDirectionTo(humanPos);
					moveInDirection(movementSpeed::walk);
				}
				else {
					//Si humain et zombi trop loin pour les voir, marche dans la direction qu'il allait déjà
					moveInDirection(movementSpeed::walk);
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

void Human::moveInDirection(movementSpeed movementSpeed)
{
	if (movementSpeed == movementSpeed::run)
	{
		if (mEnergy)
		{
			QPointF newPosition(pos().x() + mMovementDirection.x()*mRunSpeed, pos().y() + mMovementDirection.y()*mRunSpeed);
			checkForWalls(newPosition,mRunSpeed);
			this->setPos(newPosition);
			ReduceEnergy();
		}
		else
		{
			QPointF newPosition(pos().x() + mMovementDirection.x()*mWalkSpeed, pos().y() + mMovementDirection.y()*mWalkSpeed);
			checkForWalls(newPosition,mWalkSpeed);
			this->setPos(newPosition);
		}
	}
	else {
		QPointF newPosition(pos().x() + mMovementDirection.x()*mWalkSpeed, pos().y() + mMovementDirection.y()*mWalkSpeed);
		checkForWalls(newPosition,mWalkSpeed);
		this->setPos(newPosition);
		AddEnergy();
	}
}

void Human::checkForWalls(QPointF &newPosition,qreal movementSpeed)
{
	//Si on tourne déjà, on continue dans les direction de tournant donné
	if (!mIsTurning)
	{
		//Si on s'en va dans un mur, on ajuste la direction et on calcul les direction a prendre pour faire le tournant au complet
		if ((newPosition.x() < mSizeHumanoid * 2) || (newPosition.x() > ParamSim::SceneWidth() - (mSizeHumanoid * 2)) ||
			(newPosition.y() < mSizeHumanoid*2) || (newPosition.y() > ParamSim::SceneHeight()-(mSizeHumanoid*2)))
		{
			mIsTurning = true;
			//On trouve l'angle de mouvement actuel
			qreal directionAngle = atan(mMovementDirection.y() / mMovementDirection.x());
			for (int i{ 0 }; i < mNumberOfTurningDirection; ++i)
			{
				qreal newAngle = directionAngle + (mRotationAngle / mNumberOfTurningDirection);
				QVector2D newDirection(cos(newAngle), sin(newAngle));
				mTurningDirection[i] = newDirection;
			}
			mTurningAtPosition = 1;
			newPosition = QPointF(pos().x() + mTurningDirection[0].x()*movementSpeed, pos().y() + mTurningDirection[0].y()*movementSpeed);
			mMovementDirection = mTurningDirection[0];
		}
	}
}

void Human::setDirectionTo(QPointF positionTo)
{
	//We set the direction of the entity going to that entity
	qreal movementX = ( positionTo.x()- pos().x());
	qreal movementY = ( positionTo.y()- pos().y());
	qreal directionNorm = sqrt(movementX*movementX + movementY*movementY);
	mMovementDirection = QVector2D(movementX / directionNorm, movementY / directionNorm);

}

void Human::setDirectionFrom(QPointF positionFrom)
{
	//We set the direction of the entity going away from that point
	qreal movementX = (pos().x() - positionFrom.x());
	qreal movementY = (pos().y() - positionFrom.y());
	qreal directionNorm = sqrt(movementX*movementX + movementY*movementY);
	mMovementDirection = QVector2D(movementX / directionNorm, movementY / directionNorm);

}

bool Human::IsDead()
{
	if (mAge == mDeathAge) {
		return true;
	}
	return false;
}

void Human::Reproduction()
{
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

bool Human::VirusTransmission()
{
	if (mVirus)
	{
		//Infecte l<humain qui est proche
	}
	return false;
}

void Human::MilitaryPainter(QPainter * painter)
{
	Military * military = dynamic_cast<Military*>(mSpecifier);
	if (military)
	{
		mBrushColor = Qt::darkGreen;
		mPenColor = Qt::darkGreen;
	}
}

void Human::ChildrenPainter(QPainter * painter)
{
	Children * child = dynamic_cast<Children*>(mSpecifier);
	if (child)
	{
		mBrushColor = Qt::darkYellow;
		mPenColor = Qt::darkYellow;
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
	mResistanceGenerator = new RandomNorm(mResistanceMean, mResistanceMean*mResistanceDeviation);
	mDeathAgeGenerator = new RandomNorm(mDeathAgeMean, mDeathAgeMean*mDeathAgeDeviation);
	mVirusResistance = mResistanceGenerator->Generate();
	mDeathAge = mDeathAgeGenerator->Generate();
	QStatSim::IncNbrHumain();
	QStatSim::IncNbrNomVivant(mName);
}

void Human::BaseHumanInit(newHumanParameters *humanParameters) 
{
	mBrushColor = mHumanColor;
	mPenColor = mHumanColor;
	mResistanceGenerator = new RandomNorm(humanParameters->avrgVirusResistance, humanParameters->avrgVirusResistance*mResistanceDeviation);
	mDeathAgeGenerator = new RandomNorm(humanParameters->avrgDeathAge, humanParameters->avrgDeathAge*mDeathAgeDeviation);
	mVirusResistance = abs(mResistanceGenerator->Generate());
	mDeathAge = abs(mDeathAgeGenerator->Generate());
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

void Human::CreateVirus()
{
	if (!mVirus)
	{
		mVirus = new Virus();
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
		mSpecifier = new Children(nullPtr,this);
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

bool Human::IsBecomingZombie(bool biteByZombie)
{
	if (mVirus->IsBecomingZombit() || biteByZombie)
	{
		DeleteSpecifier();
		return true;
	}
	return false;
}

void Human::IsBecomingAdult()
{
	if (mAge >= Children::AgeEnd())
	{
		DeleteSpecifier();
		if (mWillBeocmeMilitary)
		{
			CreateMilitary();
		}
	}
}

void Human::IsRetiring()
{
	if (mAge >= Military::AgeEnd())
	{
		DeleteSpecifier();
	}
}
