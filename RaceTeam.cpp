#include "RaceTeam.h"
#include "GrandPrix.h"
#include "RaceState.h"

RaceTeam::RaceTeam()
{
	throw "Not yet implemented";
}

RaceTeam::~RaceTeam()
{
}

LapResult *RaceTeam::performLap(int driverIndex, Circuit *circuit)
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