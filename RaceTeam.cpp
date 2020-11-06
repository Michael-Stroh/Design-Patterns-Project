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
}

RaceTeam::RaceTeam(string teamName){

	// FOR TESTING PURPOSES ONLY

	this->teamName = teamName;
	this->drivers = vector<Driver *>();
	this->drivers.push_back(new Driver(teamName + " : Driver 1"));
	this->drivers.push_back(new Driver(teamName + " : Driver 2"));
	srand((unsigned)time(0));

}

RaceTeam::~RaceTeam()
{
	
}

LapResult *RaceTeam::performLap(int driverIndex, Circuit *circuit)
{
	// drivers[driverIndex] drive on circuit
	// return lapresult
	// throw "Not yet implemented";

	// FOR TESTING PURPOSES ONLY
	LapResult *result = new LapResult(this->drivers[driverIndex]->getName(), this->teamName, rand()/10000000);
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

void RaceTeam::informGrandPrixs(vector<GrandPrix *> g)
{
	this->grandPrixs = g;
}

void RaceTeam::setRaceState(RaceState* s){
	throw "Not yet implemented";
}

Driver *RaceTeam::getDriver(int i){
	// FOR TESTING PURPOSES ONLY
	return this->drivers[i];
}

float RaceTeam::getCarLapTime(int index, Circuit* circuit)
{
	float ans = 0;
	throw "Not Implemented Yet";

	return ans;
}

float RaceTeam::getDriverLapTime(int index, Circuit* circuit)
{
	float ans = 0;
	throw "Not Implemented Yet";

	return ans;
}


Budget* RaceTeam::createSeasonBudget()
{
	throw "Not Implemented Yet";
}

string RaceTeam::getName(){
	return this->teamName;
}

const float RaceTeam::moneyPerGrandPrix = 1000;	//Subject to change