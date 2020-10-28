#include "Strategies.h"

Strategies::Strategies() {
	raceStrategy = new RaceStrategy();
	logisticsStrategy = new LogisticsStrategy();
	month =0;
}

Strategies::~Strategies() {

}

Strategies::Strategies( RaceStrategy* r, LogisticsStrategy* l ) {
	raceStrategy = r;
	logisticsStrategy =l;
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
