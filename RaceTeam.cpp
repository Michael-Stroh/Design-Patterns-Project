#include "RaceTeam.h"
#include "GrandPrix.h"
#include "RaceState.h"

RaceTeam::RaceTeam()
{
	/*
		Tim's Portion: The Construction of the Car Builder and the Car/s followed by the construction of the Engineering Departments
	*/
		builder = new CarBuilder();
		car = builder->buildCar();
		departments.push_back(new EngineDepartment(nullptr, 0));		//These values may have to change
		departments.push_back(new ElectronicsDepartment(nullptr, 0));
		departments.push_back(new ChassisDepartment(nullptr, 0));
		departments.push_back(new AerodynamicsDepartment(nullptr, 0));
	/*
		End Of Tim's Portion
	*/
}

RaceTeam::~RaceTeam()
{
	/*
		Tim's Portion: The Construction of the Car Builder and the Car/s followed by the construction of the Engineering Departments
	*/
	delete builder;
	delete car;
	for (int i = 0; i < departments.size(); ++i)
		delete departments[i];
	/*
		End Of Tim's Portion
	*/
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

const float RaceTeam::moneyPerGrandPrix = 1000;	//Subject to change