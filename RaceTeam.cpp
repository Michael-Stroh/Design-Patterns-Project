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
	Logger::debug("RaceTeam::constructor", "creating engineering crew");
		engineeringCrew = new EngineeringCrew();
	Logger::debug("RaceTeam::constructor", "engineering crew created");
		lapCount = 0;

		raceState = nullptr;
		seasonResult = nullptr;
		qualifyingRaceResult = nullptr;
		officialRaceResult = nullptr;
		Strategy = nullptr;
		
	engineeringCrew = new EngineeringCrew();
	/*
		End Of Tim's Portion
	*/

	/*
		Brents Portion: Create Drivers and RaceTeam Name 
	*/
		//function file reader
	/*
		End Of Brents Portion
	*/
		Logger::debug("End of the RaceTeam Constructor", "");
		//Brents Portion: Create Drivers and RaceTeam Name
	
	//fuunction file reader
/*
	End Of Brents Portion
*/
	Strategy = new Strategies();
}

RaceTeam::RaceTeam(string teamName, vector<Driver*> d) {
	Logger::debug("RaceTeam::constructor", "creating engineering crew");
	engineeringCrew = new EngineeringCrew();
	Logger::debug("RaceTeam::constructor", "engineering crew created");
	lapCount = 0;

	Logger::debug("RaceTeam::Constructor", "assigning Teams");
	this->teamName = teamName;
	Logger::debug("RAceTeam::constructor", "Assigning Drivers");
	this->drivers = d;
	//drivers[0]->displayDriver();										//delete me1
	Logger::debug("RAceTeam::constructor", "Creating new Strategy");
	Strategy = new Strategies();								//leave in, Not in Brent's
	Logger::debug("RAceTeam::constructor", "new Strategy created");
}

//For testing, should not be used in main
RaceTeam::RaceTeam(string teamName){

	// FOR TESTING PURPOSES ONLY
	//this->teamName = teamName;
	//this->drivers = vector<Driver *>();
	//this->drivers.push_back(new Driver(teamName + " : Driver 1"));	//commented out since Driver is a pure virtual class
	this->teamName = teamName;
	this->drivers = vector<Driver*>();
	//this->drivers.push_back(new Driver(teamName + " : Driver 1"));	//commented out since Driver is a pure virtual class *abstract class*
	//this->drivers.push_back(new Driver(teamName + " : Driver 2"));
	//srand((unsigned)time(0));

}

RaceTeam::~RaceTeam()
{
	drivers.clear();
	delete engineeringCrew;
	delete Strategy;

	/*
		Brent delete drivers: strategies. DONT DELTE GRANDPRIXS ITS DONE IN MAIN!!!!
	*/
}

LapResult *RaceTeam::performLap(int driverIndex, RaceTrack *circuit)
{
	float extraTime =0;

	/*
		Pitstop Checking: Brent use raceState to decide
	*/
	//increment lapCount if raceState is official
	//brent do calculations

	if (raceState->getStateName() == "Official") {
		PitStopStrategy* ps = Strategy->getRaceStrategy(driverIndex)->getPitStopStrategy();
		lapCount++;
		changeStrategiesBasedOnPosition(drivers.at(driverIndex), driverIndex);
		//check for pit stop in race
		if (ps->CheckForPitStop(lapCount)) {
			ps->CallPitStop();
			Strategy->getRaceStrategy(driverIndex)->getDriverStrategy()->changeStrategy();
			extraTime += circuit->getAvgPitStops();
		}
	}

	/*
		EngineeringCrew: car run lap function depending on race state (Tim Kayla)
	*/
	int agg = (drivers[driverIndex]->getAggression()/30) -1;
	//quick test just to be sure
	if (agg < 0)
		agg = 1;
	if (agg > 2)
		agg = 1;
	engineeringCrew->getCar()->runLap(agg);

	/**
		Driver part
	*/
	float driverTime = this->getDriverLapTime(driverIndex, circuit); 

	/**
		CarPart
	*/
	float carTime = this->getCarLapTime(driverIndex, circuit);			//check this value
	Logger::debug("RaceTeam::performLap car Time", to_string(carTime));
	float avgTime = (driverTime + carTime) / 2;

	if (extraTime != 0)
		avgTime += extraTime;

	Logger::debug("RaceTEam::getLapResult", to_string(avgTime));

	if (circuit->getBestLapTime() + 10 < avgTime) {
		//bad lap 3 seconds slower
		Strategy->getRaceStrategy(driverIndex)->getDriverStrategy()->lapChanges(false);
	}
	else {
		//good lap
		Strategy->getRaceStrategy(driverIndex)->getDriverStrategy()->lapChanges(true);
	}
	LapResult* result = new LapResult(this->drivers[driverIndex]->getName(), this->teamName, avgTime);
	return result;
}

void RaceTeam::informSeasonResult(Result *result)
{
	this->seasonResult = dynamic_cast<RaceSeasonResult *>(result);

}

void RaceTeam::updateQualifyingRaceResult(Result *result)
{

	this->qualifyingRaceResult = dynamic_cast<RaceResult *>(result);
}

void RaceTeam::updateOfficialRaceResult(Result* result)
{
	this->officialRaceResult = dynamic_cast<RaceResult*>(result);
}

/*
	@todo cry

/*
	@Brent Must implement
	@todo cry
*/
void RaceTeam::informGrandPrixs(vector<GrandPrix *> g)
{

	/*
		Tim Portion Brent please don't delete
	*/
	engineeringCrew->calculateBudget(g.size());
	/*
		End of Tim's Portion
	*/

	//Create Strategy and all the shit that goes with it

	this->grandPrixs = g;
}

void RaceTeam::setRaceState(RaceState* s){
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

Driver *RaceTeam::getDriver(int i){
	// FOR TESTING PURPOSES ONLY
	return this->drivers[i];
	return this->drivers.at(i);
}

float RaceTeam::getCarLapTime(int index, RaceTrack * circuit)
{
	//Logger::debug("RaceTeam::getCarLapTime", "printing car stats");
	
	//doesnt need iterators for raceTrack
	float ans = 0;
	CarComposite* car = engineeringCrew->getCar();	
	float numCorners = 1.0 * circuit->getCorners();
	float straightDistance = circuit->getStraightDistance();
	float windForce = circuit->getWindForce();

	//max corners = 23, max wind = 14.478, max straight = 1233
	//min Corners: 10  Wind:  0.641  Straight Distance: 1000.00

	float weightedSum = (windForce * 34.5351) + (numCorners * 21.7391) + (straightDistance *0.40551);
	float speed_portion = ((straightDistance * 0.40551) / weightedSum) * engineeringCrew->getCar()->getSpeed();
	float acceleration_portion = ((windForce * 34.5351) / weightedSum) * engineeringCrew->getCar()->getAcceleration();
	float handling_portion = ((numCorners * 21.7391) / weightedSum) * engineeringCrew->getCar()->getHandling();

	ans = speed_portion + acceleration_portion + handling_portion;
	float portionOfBestTime = ((float)100.0 - ans) / 100.0;
	ans = circuit->getBestLapTime() * (portionOfBestTime / 2) + circuit->getBestLapTime();

	return ans;
}

float RaceTeam::getDriverLapTime(int index, RaceTrack * circuit)
{
	/**
		Brent to do calcultions
	*/
	Logger::debug("RaceTeam::getDriverLapTIme", "");
	srand(time(NULL));
	Logger::debug("RaceTeam::getDriverLapTIme", "get rs");
	RaceStrategy* rs = Strategy->getRaceStrategy(index);
	Logger::debug("RaceTeam::getDriverLapTIme", "get ts");
	TyreStrategy* ts = rs->getTyreStrategy();
	Logger::debug("RaceTeam::getDriverLapTIme", "get ds");
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


	return ans + circuit->getBestLapTime();
}

void RaceTeam::changeStrategiesBasedOnPosition(Driver* d, int index) {
	// negative number decrease aggression as driver is performing well
	// negative number decrease aggression as driver is performing well
	float num = ((RaceResult*)officialRaceResult)->getDriverPerformanceRating(d->getName());
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
	Strategy->getRaceStrategy(index)->getDriverStrategy()->changeAggressionDueToPositions(amount);
}

void RaceTeam::prepareForNextRace() 
{
	/*
		Tim portion
	*/
	//Algorithm is as follows:
	//update the budgets of the department
	engineeringCrew->updateDepartmentBudgets();
	engineeringCrew->prepareForNextRace();
	engineeringCrew->setCar((CarComposite*)(engineeringCrew->getNextSeasonCar()->clone()));
	/*
	
	*/
}

void RaceTeam::startRace() 
{
	/*
		Tims portion
	*/
	lapCount = 0;
	engineeringCrew->getCar()->setFuel(100);		//Just a placeHolder. Kayla can gooi here if she wants
	/*
		End Tim's Portion
	*/
}

void RaceTeam::endRace() 
{
	/*
		Tims Portion
	*/
	engineeringCrew->getCar()->resetAfterRace();
	lapCount = 0;
	/*
		End Tim's Portion
	*/
}

void RaceTeam::decideNextStrategy( GrandPrix* gp ) 
{
	Logger::debug("RaceTeam::decideNextStrategy", "");
	Strategy->setRaceStrategy(drivers[0], drivers[1], gp->getCircuit()->getName());
}


void RaceTeam::endOfGrandPrix(string name)
{
	Strategy->endOfRace(name);
}

string RaceTeam::getName() {
	return this->teamName;
}



