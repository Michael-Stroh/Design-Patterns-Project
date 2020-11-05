#include "GrandPrix.h"

GrandPrix::GrandPrix(): circuit( nullptr ), race( new Race() ), result( new GrandPrixResult( ) ) {

}

GrandPrix::GrandPrix( RaceTrack* track ): circuit( track ), race( new Race() ), result( new GrandPrixResult( ) ) {

}

GrandPrix::~GrandPrix() {

	//free the race pointer
	delete race;

	//free the result pointer
	delete result;
}

Result* GrandPrix::runGrandPrix( vector< RaceTeam* > teams ) {

    // Perform the practice race
    this->race->setState( "Practice" );
    Result* practiceResult = this->race->runRace( nullptr, teams, circuit );

    // Perform the qualifying race
    this->race->setState( "Qualifying" );
    Result* qualifyingResult = this->race->runRace( nullptr, teams, circuit );

    // Perform the official race
    this->race->setState( "Official" );
    Result* officialResult = this->race->runRace( qualifyingResult, teams, circuit );

    // Add official race's result to the grand prix's result, return the grand prix's result
    this->result->addResult( officialResult );
    return this->result;

}

void GrandPrix::displayResult() {

	result->print();
}

void GrandPrix::setCircuit( RaceTrack* changeCircuit ) {

	circuit = changeCircuit;
}