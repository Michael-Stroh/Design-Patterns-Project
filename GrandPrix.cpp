#include "GrandPrix.h"
#include "RaceResult.h"

GrandPrix::GrandPrix() {

	this->circuit = NULL;
	this->race = new Race();
	this->result = new GrandPrixResult();
}

GrandPrix::GrandPrix( Circuit* c ) {

	this->circuit = c;
	this->race = new Race();
	this->result = new GrandPrixResult();
}

GrandPrix::~GrandPrix() {

	//free the race pointer
	delete race;

	//free the result pointer
	delete result;
}

Result* GrandPrix::runGrandPrix( vector< RaceTeam* >* teams ) {

	// Perform the practice race
	string var = "Practice";
	this->race->setState(new PracticeState());
	RaceResult *practiceResult = new RaceResult(this->race->runRace(NULL, teams, this->circuit));

	// Perform the qualifying race
	this->race->setState(new QualifyingState());
	RaceResult *qualifyingResult = new RaceResult(this->race->runRace(NULL, teams, this->circuit));

	// Perform the official race
	this->race->setState(new OfficialState());
	RaceResult *officialResult = new RaceResult(this->race->runRace(qualifyingResult, teams, this->circuit));

	// Add official race's result to the grand prix's result, return the grand prix's result
	this->result->addResult(officialResult);
	return this->result;
}

void GrandPrix::displayResult() {

	this->result->print();
}

void GrandPrix::setCircuit( Circuit* changeCircuit ) {

	this->circuit = changeCircuit;
}
