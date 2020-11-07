#include "RaceTeam.h"
#include "GrandPrix.h"
#include "RaceState.h"
#include <ctime>
using namespace std;

RaceTeam::RaceTeam()
{
	/*
		Tim's Portion: The Construction of the Engineering Crew that will create and improve the cars.
	*/
	engineeringCrew = new EngineeringCrew();
	/*
		End Of Tim's Portion
	*/

	/*
		Brents Portion: Create Drivers and RaceTeam Name
	*/
	//fuunction file reader
/*
	End Of Brents Portion
*/
	makeDrivers();
	Strategy = new Strategies();
}

RaceTeam::RaceTeam(string teamName, vector<Driver*> d) {
	this->teamName = teamName;
	this->drivers = d;
}

//For testing, should not be used in main
RaceTeam::RaceTeam(string teamName) {

	// FOR TESTING PURPOSES ONLY
	this->teamName = teamName;
	this->drivers = vector<Driver*>();
	//this->drivers.push_back(new Driver(teamName + " : Driver 1"));	//commented out since Driver is a pure virtual class *abstract class*
	//this->drivers.push_back(new Driver(teamName + " : Driver 2"));
	srand((unsigned)time(0));

}

RaceTeam::~RaceTeam()
{
	drivers.clear();
	delete engineeringCrew;

	/*
		MIKE ask people before you edit there code - EG DONT CHANGE MY SHIT without asking
	*/
}

LapResult* RaceTeam::performLap(int driverIndex, RaceTrack* circuit)
{
	float extraTime = 0;

	/*
		Pitstop Checking: Brent use raceState to decide
	*/

	if (raceState->getStateName() == "Official") {
		PitStopStrategy* ps = Strategy->getRaceStrategy(driverIndex)->getPitStopStrategy();
		lapCount++;
		changeStrategiesBasedOnPosition(drivers.at(driverIndex));
		//check for pit stop in race
		if (ps->CheckForPitStop()) {
			ps->CallPitStop();
			Strategy->getRaceStrategy(driverIndex)->getDriverStrategy()->changeStrategy();
			extraTime += circuit->getAvgPitStops();
		}
	}

	/*
		EngineeringCrew: car run lap function depending on race state (Tim Kayla)
	*/

	/**
		Driver part
	*/
	float driverTime = this->getDriverLapTime(driverIndex, circuit);

	/**
		CarPart
	*/
	float carTime = this->getCarLapTime(driverIndex, circuit);
	float avgTime = (driverTime + carTime) / 2;

	if (extraTime != 0)
		avgTime += extraTime;

	if (circuit->getBestLapTime() + 3 < avgTime) {
		//bad lap 3 seconds slower
		Strategy->getRaceStrategy()->getDriverStrategy(driverIndex)->lapChanges(false);
	}
	else {
		//good lap
		Strategy->getRaceStrategy()->getDriverStrategy(driverIndex)->lapChanges(true);
	}
	LapResult* result = new LapResult(this->drivers[driverIndex]->getName(), this->teamName, avgTime);
	return result;
}

void RaceTeam::informSeasonResult(Result* result)
{
	this->seasonResult = dynamic_cast<RaceSeasonResult*>(result);
}

void RaceTeam::updateQualifyingRaceResult(Result* result)
{
	this->qualifyingRaceResult = dynamic_cast<RaceResult*>(result);
}

void RaceTeam::updateOfficialRaceResult(Result* result)
{
	this->officialRaceResult = dynamic_cast<RaceResult*>(result);
}

/*
	@todo cry
*/
void RaceTeam::informGrandPrixs(vector<GrandPrix*> g)
{

	/*
		Tim Portion Brent please don't delete
	*/
	engineeringCrew->calculateBudget(g.size());
	/*
		End of Tim's Portion
	*/




	this->grandPrixs = g;
}

void RaceTeam::setRaceState(RaceState* s) {
	if (raceState == nullptr)
	{
		raceState = s;
	}
	else
	{
		delete raceState;
		raceState = s;
	}
}

Driver* RaceTeam::getDriver(int i) {
	// FOR TESTING PURPOSES ONLY
	return this->drivers.at(i);
}

//Cicruit should be Composite Road for iterator
float RaceTeam::getCarLapTime(int index, RaceTrack* circuit)
{//okay??

	float ans = 0;

	return ans;
}

float RaceTeam::getDriverLapTime(int index, RaceTrack* circuit)
{
	srand(time(NULL));
	RaceStrategy* rs = Strategy->getRaceStrategy(index);
	TyreStrategy* ts = rs->getTyreStrategy();
	DriverStrategy* ds = rs->getDriverStrategy();

	int agg = ds->getDriver()->getAggression();
	int grip = ts->getTyres().back()->getGrip();
	int dur = ts->getTyres().back()->getDurability();

	float ans = ceil((agg * grip * dur) / (100 * 90 * 100) * circuit->getCorners());

	float error = ds->getDriver()->getErrorProne() * 100;
	int i = rand() * 100 + 1;
	//additional time per error
	ans = (circuit->getCorners() - ans) * 0.3;
	if ((error - 100) > i) {
		ans += 1;
	}

	return ans;
}

void RaceTeam::changeStrategiesBasedOnPosition(Driver* d) {
	// negative number decrease aggression as driver is performing well
	float num = officialRaceResult->getDriverPerformanceMetric(d->getName());
	int amount = 0;
	if (num != 0.5) {
		if (num > 0.5) {
			if (num == 0.75) {
				amount = -2;
			}
			else {
				if (num >= 75) {
					amount = -4;
				}
				else {
					amount = -1;
				}
			}
		}
		else if (num < 0.5) {
			if (num == 0.25) {
				amount = 2;
			}
			else {
				if (num >= 0.25) {
					amount = 1;
				}
				else {
					amount = 4;
				}
			}
		}
	}
	Strategies->changeAggressionDueToPositions(amount);
}

void RaceTeam::decideNextStrategy(GrandPrix* gp)
{
	Strategy->setRaceStrategy(drivers[0], drivers[1], gp->getCircuit());
}

void RaceTeam::endOfGrandPrix(string name)
{
	Strategies->endOfRace(name);
}


Budget* RaceTeam::createSeasonBudget()
{
	throw "Not Implemented Yet";
}

void RaceTeam::prepareForNextRace()
{
}

string RaceTeam::getName() {
	return this->teamName;
}



