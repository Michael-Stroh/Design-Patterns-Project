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
	this->result = this->state->runRace( _result, teams, circuit );
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
