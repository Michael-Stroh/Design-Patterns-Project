#include "Strategies.h"

Strategies::Strategies() {
	raceStrategy = new RaceStrategy();
	logisiticStrategy = new logisiticStrategy();
}

Strategies::Strategies(RaceStrategy* r, LogisticStrategy* l) {
	// TODO - implement Strategies::Strategies
	this->raceStrategy = r;
	this->logisiticStrategy = l;
}

int Strategies::getLapNumber() {
	return this->lapNumber;
}

void Strategies::checkLogistics() {
	//todo check after each race for need of logisitics, + before the season will start
}

void  Strategies::setRaceStrategy(RaceStrategy* rs) {
	this->raceStrategy = rs;
}