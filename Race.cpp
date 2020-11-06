#include "Race.h"

Race::Race(): state( nullptr ), result( nullptr ), raceSubject( new RaceSubject() ),
			  practiceState( new PracticeState() ), qualifyingState( new QualifyingState() ),
			  officialState( new OfficialState() ) {

}

Race::~Race() {

    delete state;
    delete raceSubject;
    delete result;
    delete practiceState;
    delete qualifyingState;
    delete officialState;
}

Result* Race::runRace( Result *_result, vector<RaceTeam *> teams, RaceTrack *circuit )
{
	startRace();
	this->result = this->state->runRace( _result, teams, circuit );
	endRace();
	return this->result;
}

void RaceTeam::startRace()
{
	//todo for each team call startRace
}

void RaceTeam::endRace()
{
	//todo for each team call endRace
}

void Race::setState( string _state )
{
	if (_state == "Practice")
	{
		Logger::debug("Setting Race State", "State set to practice");
		this->state = practiceState;
	}
	else if (_state == "Qualifying")
	{
		Logger::debug("Setting Race State", "State set to qualifying");
		this->state = qualifyingState;
	}
	else if (_state == "Official")
	{
		Logger::debug("Setting Race State", "State set to official");
		this->state = officialState;
	}
}

void Race::setRaceSubject( RaceSubject *race )
{
	this->raceSubject = race;
}
