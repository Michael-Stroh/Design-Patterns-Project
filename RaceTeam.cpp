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
}

//For testing, should not be used in main
RaceTeam::RaceTeam(string teamName){

	// FOR TESTING PURPOSES ONLY
	this->teamName = teamName;
	this->drivers = vector<Driver *>();
	//this->drivers.push_back(new Driver(teamName + " : Driver 1"));	//commented out since Driver is a pure virtual class
	//this->drivers.push_back(new Driver(teamName + " : Driver 2"));
	srand((unsigned)time(0));

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

//Cicruit should be Composite Road for iterator
float RaceTeam::getCarLapTime(int index, RaceTrack * circuit)
{
	//doesnt need iterators for raceTrack
	float ans = 0;
	throw "Not Implemented Yet";

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


Budget* RaceTeam::createSeasonBudget()
{
	throw "Not Implemented Yet";
}

string RaceTeam::getName(){
	return this->teamName;
}

