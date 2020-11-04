#include "Strategies.h"

Strategies::Strategies(Driver* driver, CompositeRoad* cr) {
	raceStrategy = new RaceStrategy(driver, cr->getRoad(0));
	logisticsStrategy = new LogisticsStrategy();
	month =0;
}

Strategies::~Strategies() {

}


int Strategies::getMonth(){
	return month;
}

void Strategies::nextMonth(){
	month += 1;
	checkLogisitics();
}

void Strategies::setMonth(int month){
	this->month = month;
}	

void checkLogisitics(){

}
