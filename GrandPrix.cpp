#include "GrandPrix.h"
#include "RaceResult.h"

GrandPrix::GrandPrix()
{
	this->circuit = NULL;
	this->race = new Race();
	this->result = new GrandPrixResult();
}

GrandPrix::GrandPrix(Circuit *c)
{
	this->circuit = c;
	this->race = new Race();
	this->result = new GrandPrixResult();
}

Result *GrandPrix::runGrandPrix(vector<RaceTeam *> *teams)
{
	// Perform the practice race
	this->race->setState("Practice");
	RaceResult *practiceResult = new RaceResult(this->race->runRace(NULL, teams, this->circuit));

	// Perform the qualifying race
	this->race->setState("Qualifying");
	RaceResult *qualifyingResult = new RaceResult(this->race->runRace(NULL, teams, this->circuit));

	// Perform the official race
	this->race->setState("Official");
	RaceResult *officialResult = new RaceResult(this->race->runRace(qualifyingResult, teams, this->circuit));

	// Add official race's result to the grand prix's result, return the grand prix's result
	this->result.addResult(officialResult);
	return this->result;
}

void GrandPrix::displayResult()
{
	this->result->print();
}

void GrandPrix::setCircuit(Circuit *)
{
	this->circuit = c;
}
