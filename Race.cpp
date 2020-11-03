#include "Race.h"

Race::Race()
{

	this->state = NULL;
	this->result = NULL;
	this->raceSubject = new raceSubject();
	this->practiceState = new PracticeState();
	this->qualifyingState = new QualifyingState();
	this->officialState = new OfficialState();
}

Race::~Race()
{
	if (this->state)
	{
		delete this->state;
	}
	this->state = NULL;

	if (this->raceSubject)
	{
		delete this->raceSubject;
	}
	this->raceSubject = NULL;

	if (this->result)
	{
		delete this->result;
	}
	this->result = NULL;

	if (this->practiceState)
	{
		delete this->practiceState;
	}
	this->practiceState = NULL;

	if (this->qualifyingState)
	{
		delete this->qualifyingState;
	}
	this->qualifyingState = NULL;

	if (this->officialState)
	{
		delete this->officialState;
	}
	this->officialState = NULL;
}

Result *Race::runRace(Result *_result, vector<RaceTeam *> *teams, Circuit *circuit)
{
	this->result = this->state->runRace(_result, teams, circuit);
	return this->result;
}

void Race::setState(string _state)
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

void Race::setRaceSubject(RaceSubject *race)
{
	this->raceSubject = race;
}
