#include "Strategies.h"

Strategies::Strategies(){

	setLogistics();
}

Strategies::~Strategies() {

	races.clear();
}

void Strategies::setRaceStrategy(Driver* driver, string name){

	raceStrategy = new RaceStrategy( driver, logisticsStrategy->getRace( name ) );
}

void Strategies::endOfRace( string name ) {

	//delete raceStrategy;
	logisticsStrategy->endOfRace( name );
}

RaceStrategy* Strategies::getRaceStrategy() {

	return raceStrategy;
}

void Strategies::setLogistics() {

	logisticsStrategy =  new LogisticsStrategy(races);
}

void Strategies::print() {

	for( int i =0; i < 21; i++){

		RaceTrack* temp = races.at(i);
		cout << temp->getName() << " " << temp->getDistance() << " " << temp->getLaps() << endl;
	}
}

vector<RaceTrack*> Strategies::getRaceTrack() {

	return races;
}

int Strategies::getMonth() {

	return 0;
}

void Strategies::setMonth( int date ) {


}















