#include "RaceStrategy.h"


RaceStrategy::RaceStrategy(Driver* driver, RaceTrack* rt) {
	this->rt = rt;
	this->driver = driver;
	setTyreStrategy(rt);
	setDriverStrategy(tyreStrategy);
	setPitStopStrategy(tyreStrategy);
}

RaceStrategy::~RaceStrategy(){
	delete rt;
	delete driver;
	delete pitStopStrategy;
	delete driverStrategy;
	delete tyreStrategy;
}

void RaceStrategy::setPitStopStrategy(TyreStrategy* ts) {
	pitStopStrategy = new PitStopStrategy(ts);
}


void RaceStrategy::setDriverStrategy(TyreStrategy* ts) {
	driverStrategy = new DriverStrategy(ts);
	driverStrategy->setDriver(driver);
}

void RaceStrategy::setTyreStrategy(RaceTrack*  rt) {
	tyreStrategy = new TyreStrategy(rt);
}

/**
			
*/
DriverStrategy*  RaceStrategy::getDriverStrategy(){
	return driverStrategy;
}		
/**
*/
TyreStrategy* RaceStrategy::getTyreStrategy(){
	return tyreStrategy;
}
		
/**
*/
PitStopStrategy* RaceStrategy::getPitStopStrategy(){
	return pitStopStrategy;
}








