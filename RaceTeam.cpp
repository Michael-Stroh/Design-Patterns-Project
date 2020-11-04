#include "RaceTeam.h"

RaceTeam::RaceTeam()
{
	throw "Not yet implemented";
}

RaceTeam::~RaceTeam()
{
	throw "Not yet implemented";
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

bool RaceTeam::updateOfficialRaceResult(Result *result)
{

	this->officialRaceResult = dynamic_cast<RaceResult *>(result);
}

void RaceTeam::informGrandPrix(vector<GrandPrix *> g)
{
	this->grandPrixs = g;
}