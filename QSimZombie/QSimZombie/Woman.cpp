#include "Woman.h"
#include "Children.h"
#include "QStatSim.h"
#include "Environnement.h"
#include "ParamSim.h"
#include <QPainter>


RandomNorm *Woman::mDoesReproduce{ nullptr };
int Woman::mMaxChildren{ 5 };
const int Woman::mEndFertility{ 480 }; //Age of end of fertility for the women
const int Woman::mFertilityTime{ 10 };
const QColor Woman::mWomanColor{ 242, 229, 135 };


Woman::Woman(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, int age, bool military, bool infection, QGraphicsItem *parent)
	:Human(x, y, currentEnvironnemnt, typeOfHumanoide, age, military, infection,parent),
	mCountChildren{0},
	mTickRemaining{mFertilityTime},
	mCurrentBaby{nullptr}
{
	mBrushColor = mWomanColor;
	mPenColor = mWomanColor;
	QStatSim::IncNbrFemme();
}

Woman::Woman(double x, double y, Environnement * currentEnvironnemnt, humanoideType typeOfHumanoide, bool military, bool infection, QGraphicsItem * parent)
	:Human(x, y, currentEnvironnemnt, typeOfHumanoide, military, infection, parent),
	mCountChildren{ 0 },
	mTickRemaining{ mFertilityTime },
	mCurrentBaby{ nullptr }
{
	mBrushColor = mWomanColor;
	mPenColor = mWomanColor;
	QStatSim::IncNbrFemme();

}

Woman::Woman(double x, double y, Environnement *currentEnvironnemnt, humanoideType typeOfHumanoide, newHumanParameters *humanParameters, QGraphicsItem *parent)
	:Human(x, y, currentEnvironnemnt, typeOfHumanoide, humanParameters, parent),
	mCountChildren{ 0 },
	mTickRemaining{ mFertilityTime },
	mCurrentBaby{ nullptr }
{
	mBrushColor = mWomanColor;
	mPenColor = mWomanColor;
	QStatSim::IncNbrFemme();

}


Woman::~Woman()
{
	QStatSim::DecNbrFemme();
}

void Woman::advance(int phase, int const index)
{
	if (!phase)
	{
		//On fait le advance du specifier si l'humain à un specifier
		if (mSpecifier)
		{
			HumanSpecifier::returnAdvance resultAdvance = mSpecifier->advance(phase, index);
			if (resultAdvance == HumanSpecifier::returnAdvance::newAdult)
			{
				IsBecomingAdult();
			}
		}
		else {
			if (IsDead())
			{
				//For each child, tell them their mother is dead
				for (auto & child : mListChildren)
				{
					child->LosingMother();
				}
				mEnvironnement->addDeathHumanoid(index);
				becomeZombie();
			}
			else
			{
				//Le zombi mange la femme
				if (mEnvironnement->getDistanceToClosestZombie(index) <= mEatingRange)
				{
					//For each child, tell them their mother is dead
					for (auto & child : mListChildren)
					{
						child->LosingMother();
					}
					mEnvironnement->addDeathHumanoid(index);
				}
				else if (!mTickRemaining)
				{
					GiveBirth();

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
				else if (mEnvironnement->getDistanceToClosestZombie(index) <= mViewRaySq) {
					//Zombi est visible, court dans le sens inverse					
					QPointF zombiPos = mEnvironnement->getClosestZombiPos(index);
					setDirectionFrom(zombiPos);
					moveInDirection(movementSpeed::run);
				}
				else if (mEnvironnement->getDistanceToclosestHuman(index) <= mEatingRange) {
					//Si très près d'un autre humain, transmission de virus et s'éloigne de lui en marchant
					VirusTransmission();
					tryReproduction(index);
					QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
					setDirectionFrom(humanPos);
					moveInDirection(movementSpeed::walk);
				}
				else if (mEnvironnement->getDistanceToclosestHuman(index) <= mViewRaySq) {
					//Si humain visible, marche vers lui
					QPointF humanPos = mEnvironnement->getClosestHumanPos(index);
					setDirectionFrom(humanPos);
					moveInDirection(movementSpeed::walk);
				}
				else {
					//Si humain et zombi trop loin pour les voir, marche dans la direction qu'il allait déjà
					moveInDirection(movementSpeed::walk);
				}
			}
			if (mCurrentBaby)
			{
				mTickRemaining--;

			}

		}
	}
}

void Woman::advance(int phase)
{
	advance(phase, 0);
}

void Woman::GiveBirth()
{	
	//We set the position of the new children being born 
	mCurrentBaby->setPos(this->pos().x()+ QHumanoid::mSizeHumanoid,this->pos().y()+ QHumanoid::mSizeHumanoid);
	if (dynamic_cast<Children*>(mCurrentBaby->Specifier()))
	{
		mListChildren.append(dynamic_cast<Children*>(mCurrentBaby->Specifier()));

		mCountChildren++;
		mTickRemaining = mFertilityTime;

		//On ajouter l'enfant à la scene
		mEnvironnement->scene()->addItem(mCurrentBaby);
		////On affiche le nouvel humain
		//QPainter *p;
		//mCurrentBaby->paint(p, nullptr, nullptr);
		mCurrentBaby->setVisible(true);

		//On remet le pointeur du baby a nul
		mCurrentBaby = nullptr;
	}
}

int Woman::CountChildren()
{
	return mCountChildren;
}

bool Woman::Reproduction()
{
	if (mAge>mEndFertility) {
		return false;
	}
	if (mTickRemaining != mFertilityTime)
	{
		return false;
	}
	return true;
}

void Woman::tryReproduction(int const index)
{
	if (Reproduction()) {
		Human * closestHuman = mEnvironnement->getClosestHuman(index);
		if (closestHuman->who() == QHumanoid::humanoideType::human)
		{
			//Find is they conceive a baby
			mDoesReproduce = new RandomNorm(0, 1);
			if (mDoesReproduce->Generate() < (this->mFertility + closestHuman->fertility()) / 2)
			{
				createBaby(closestHuman);
			}
		}
	}
}

void Woman::createBaby(Human * father)
{

	//We get all the parameter for the baby and create a human or women that will not show until birth
	//We do an average of the parameter of the father and the mother to get the average of the new parameter of the baby.
	newHumanParameters *babyParameters = new newHumanParameters;
	babyParameters->avrgRunSpeed = (this->mRunSpeed + father->RunSpeed()) / 2;
	babyParameters->avrgWalkSpeed = (this->mWalkSpeed + father->WalkSpeed()) / 2;
	babyParameters->avrgViewRay = (this->mViewRay + father->ViewRay()) / 2;
	babyParameters->avrgFertility = (this->mFertility + father->fertility()) / 2;
	babyParameters->avrgVirusResistance = (this->mVirusResistance + father->VirusResistance()) / 2;
	babyParameters->avrgDeathAge = (this->mDeathAge + father->DeathAge()) / 2;
	
	if (this->mVirus || father->isInfected())
	{
		babyParameters->isInfected = true;
	}
	else {
		babyParameters->isInfected = false;
	}

	if (mDoesReproduce->Generate() < ParamSim::ProbNewMilitary())
	{
		babyParameters->isMilitary = true;
	}
	else {
		babyParameters->isMilitary = false;
	}

	//one chance on two to get a girl or a boy
	if (mDoesReproduce->Generate() > 0.5)
	{
		mCurrentBaby = new Human(0, 0, mEnvironnement, QHumanoid::humanoideType::human, babyParameters);		
	}
	else {
		mCurrentBaby = new Woman(0, 0, mEnvironnement, QHumanoid::humanoideType::woman, babyParameters);
	}
	mCurrentBaby->setVisible(false);
	//We set the current woman as the mother of the child
	dynamic_cast<Children*>(mCurrentBaby->Specifier())->setMother(this);

}

void Woman::LosingChild(Children * child)
{
	int i = 0;
	for (auto & children : mListChildren)
	{
		if (children == child)
		{
			mListChildren.removeAt(i);
		}
		i++;
	}
	mCountChildren--;
}



