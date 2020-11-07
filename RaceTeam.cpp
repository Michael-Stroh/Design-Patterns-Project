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
}

//For testing, should not be used in main
RaceTeam::RaceTeam(string teamName){

	// FOR TESTING PURPOSES ONLY
	//this->teamName = teamName;
	//this->drivers = vector<Driver *>();
	//this->drivers.push_back(new Driver(teamName + " : Driver 1"));	//commented out since Driver is a pure virtual class
	//this->drivers.push_back(new Driver(teamName + " : Driver 2"));
	//srand((unsigned)time(0));

}

RaceTeam::~RaceTeam()
{
	delete engineeringCrew;

	/*
		Brent delete drivers: strategies. DONT DELTE GRANDPRIXS ITS DONE IN MAIN!!!!
	*/
}

LapResult *RaceTeam::performLap(int driverIndex, RaceTrack *circuit)
{
	float extraTime =0;

	/**
		Brent Change strategies basedOn Position
	*/
	changeStratgiesBasedOnPosition();

	/*
		Pitstop Checking: Brent use raceState to decide
	*/
	//increment lapCount if raceState is official
	//brent do calculations

	/*
		EngineeringCrew: car run lap function depending on race state (Tim Kayla)
	*/
	int agg = drivers[driverIndex]->getAggression();
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
	float carTime = this->getCarLapTime(driverIndex, circuit);

	/*
		Finalize
	*/
	float avgTime = (driverTime + carTime) / 2;
	if (extraTime != 0)
		avgTime += extraTime;

	LapResult *result = new LapResult(this->drivers[driverIndex]->getName(), this->teamName, avgTime);
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

void RaceTeam::updateOfficialRaceResult(Result *result)
{

	this->officialRaceResult = dynamic_cast<RaceResult *>(result);
}

/*
	@Brent Must implement
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
	float ans = 0;
	throw "Not Implemented Yet";
	//doesnt need iterators for raceTrack
	/**
		Brent to do calcultions
	*/

	return ans;
}

void RaceTeam::changeStratgiesBasedOnPosition()
{
	/**
		For Brent to do based on race State
	*/
}

string RaceTeam::getName(){
	return this->teamName;
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

void RaceTeam::decideNextStrategy( GrandPrix* ) 
{

}

void RaceTeam::endOfGrandPrix() 
{

}

