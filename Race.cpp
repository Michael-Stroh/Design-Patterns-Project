#include "Race.h"

Race::Race() {

	// TODO - implement Race::Race
	throw "Not yet implemented";
}

Race::Race( RaceState* _state, RaceSubject* race ): state( _state ), raceSubject( race ) {

	// TODO - implement Race::Race
	throw "Not yet implemented";
}

Result* Race::runRace( Result* result, RaceTeam* teams, Circuit* circuit ) {

	// TODO - implement Race::runRace
	throw "Not yet implemented";
}

void Race::setState( RaceState* _state ) {

	state = _state;
}

void Race::setRaceSubject( RaceSubject* race ) {

	raceSubject = race;
}
