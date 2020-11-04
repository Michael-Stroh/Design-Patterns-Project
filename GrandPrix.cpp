#include "GrandPrix.h"

GrandPrix::GrandPrix(): circuit( nullptr ), race( new Race() ), result( new GrandPrixResult( ) ) {

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
    this->race->setState( "Practice" );
    Result* practiceResult = this->race->runRace( nullptr, teams, this->circuit );

    // Perform the qualifying race
    this->race->setState( "Qualifying" );
    Result* qualifyingResult = this->race->runRace( nullptr, teams, this->circuit );

    // Perform the official race
    this->race->setState( "Official" );
    Result* officialResult = this->race->runRace( qualifyingResult, teams, this->circuit );

    // Add official race's result to the grand prix's result, return the grand prix's result
    this->result->addResult( officialResult );
    return this->result;

}

void GrandPrix::populateCircuit( const string& fileName ) {

    string line;
    ifstream file;

    //file.open("../Data/races.txt");
    file.open(fileName );
    if (file.is_open()) {
        while (getline(file, line)) {
            int pos =0;
            int size = line.size();
            cout << size << endl;
            string temp = line;
            for( int i =0 ; i <  10; i++){
                pos = temp.find_first_of('|' );
                cout << temp.substr(1,pos-1) << endl;
                temp = temp.substr(pos+1, size);
            }
        }
    }
    else {
        cout << "file not found" << endl;
    }

    file.close();
}

void GrandPrix::displayResult() {

	this->result->print();
}

void GrandPrix::setCircuit( Circuit* changeCircuit ) {

	this->circuit = changeCircuit;
}
