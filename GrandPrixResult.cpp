#include "GrandPrixResult.h"

GrandPrixResult::GrandPrixResult()
{
	this->officialRaceResult = new RaceResult();
	this->driverPoints = vector<pair<string, int>>();
	this->teamPoints = vector<pair<string, int>>();
}

void GrandPrixResult::print()
{
	cout << "Drivers Championship: " << endl;
	this->printDrivers();
	cout << "Constructors Championship: " << endl;
	this->printTeams();
}

void GrandPrixResult::printDrivers()
{

	vector<pair<string, int>>::iterator it;
	for (it = this->driverPoints.begin(); it != this->driverPoints.end(); ++it)
	{
		cout << it->first << ": " << it->second << " pts" << endl;
	}
}

void GrandPrixResult::printTeams()
{
	vector<pair<string, int>>::iterator it;
	for (it = this->teamPoints.begin(); it != this->teamPoints.end(); ++it)
	{
		cout << it->first << ": " << it->second << " pts" << endl;
	}
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
