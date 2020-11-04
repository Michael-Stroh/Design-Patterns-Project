#include "Race.h"

Race::Race()
{

	this->state = nullptr;
	this->result = nullptr;
	this->raceSubject = new RaceSubject();
	this->practiceState = new PracticeState();
	this->qualifyingState = new QualifyingState();
	this->officialState = new OfficialState();
}

Race::~Race() {

    delete state;
    delete raceSubject;
    delete result;
    delete practiceState;
    delete qualifyingState;
    delete officialState;
}

Result *Race::runRace( Result *_result, vector<RaceTeam *> *teams, Circuit *circuit )
{
	this->result = this->state->runRace(_result, teams, circuit);
	return this->result;
}

void Race::setState( string _state )
{
	if (_state == "Practice")
	{
		this->state = practiceState;
	}
	else if (_state == "Qualifying")
	{
		this->state = qualifyingState;
	}
	else if (_state == "Official")
	{
		this->state = officialState;
	}
}

void Race::setRaceSubject( RaceSubject *race )
{
	this->raceSubject = race;
}
