#include "RaceTeam.h"
#include "GrandPrix.h"
#include "RaceState.h"

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

RaceTeam::~RaceTeam()
{
	
}

LapResult *RaceTeam::performLap(int driverIndex, RaceTrack *circuit)
{
	// drivers[driverIndex] drive on circuit
	// return lapresult
	throw "Not yet implemented";
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
	throw "Not yet implemented";
}

float RaceTeam::getCarLapTime(int index, RaceTrack* circuit)
{
	float ans = 0;
	throw "Not Implemented Yet";

	return ans;
}

float RaceTeam::getDriverLapTime(int index, RaceTrack* circuit)
{
	float ans = 0;
	throw "Not Implemented Yet";

	return ans;
}


Budget* RaceTeam::createSeasonBudget()
{
	throw "Not Implemented Yet";
}

const float RaceTeam::moneyPerGrandPrix = 1000;	//Subject to change