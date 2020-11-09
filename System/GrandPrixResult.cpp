#include "GrandPrixResult.h"

GrandPrixResult::GrandPrixResult()
{
	this->officialRaceResult = new RaceResult();
	this->driverPoints = vector<pair<string, int>>();
	this->teamPoints = vector<pair<string, int>>();
}

GrandPrixResult::~GrandPrixResult(){

}

void GrandPrixResult::print()
{
	Logger::blue("Grand Prix Results", this->getDriverPositions());
}

string GrandPrixResult::getDriverPositions()
{
	string driverResults = "";
	vector<pair<string, int>>::iterator it;
	vector<pair<string, int>> driverPositions = dynamic_cast<RaceResult*>(this->officialRaceResult)->getDriverResults();
	for (it = driverPositions.begin(); it != driverPositions.end(); ++it)
	{
		driverResults += to_string(it->second) + ":\t" + it->first + "\n";
	}
	return driverResults;
}

void GrandPrixResult::addResult(Result *r)
{
	RaceResult *raceResult = dynamic_cast<RaceResult *>(r);
	this->officialRaceResult = r;
	this->driverPoints = raceResult->getDriverPoints();
	this->teamPoints = raceResult->getTeamPoints();
}

vector<pair<string, int>> GrandPrixResult::getTeamPoints()
{
	return this->teamPoints;
}

vector<pair<string, int>> GrandPrixResult::getDriverPoints()
{
	return this->driverPoints;
}
