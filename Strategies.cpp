#include "Strategies.h"

Strategies::Strategies(){

	setLogisitics();
}

Strategies::~Strategies() {

	races.clear();
}

void Strategies::setRaceStrategy(Driver* driver, string name){

	raceStrategy = new RaceStrategy(driver, logisticsStrategy->getRace(name));
}

void Strategies::endOfRace(string name){

	//delete raceStrategy;
	logisticsStrategy->endOfRace(name);
}

RaceStrategy* Strategies::getRaceStrategy(){

	return raceStrategy;
}

void Strategies::setLogisitics(){

	logisticsStrategy =  new LogisticsStrategy(races);
}

void Strategies::print(){

	for( int i =0; i < 21; i++){

		RaceTrack* temp = races.at(i);
		cout << temp->getName() << " " << temp->getDistance() << " " << temp->getLaps() << endl;
	}
}


string Strategies::trim(string temp){
	string nono = "\t\n\v\f\r ";
	temp.erase(0, temp.erase(temp.find_last_not_of(nono)+1).find_first_not_of(nono));
	return temp; 
}

vector<RaceTrack*> Strategies::getRaceTrack(){
	return races;
}















