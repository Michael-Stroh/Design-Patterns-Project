#include "RaceStrategy.h"

RaceStrategy::RaceStrategy() {

	// TODO - implement RaceStrategy::RaceStrategy
	throw "Not yet implemented";
RaceStrategy::RaceStrategy(Driver* driver, RaceTrack* rt) {
	this->rt = rt;
	this->driver = driver;
	setTyreStrategy(rt);
	setDriverStrategy(tyreStrategy);
	setPitStopStrategy(tyreStrategy);
}

void RaceStrategy::setPitStopStrategy() {
RaceStrategy::~RaceStrategy(){
	delete rt;
	delete driver;
	delete pitStopStrategy;
	delete driverStrategy;
	delete tyreStrategy;
}

	// TODO - implement RaceStrategy::setPitCrewStrategy
	throw "Not yet implemented";
void RaceStrategy::setPitStopStrategy(TyreStrategy* ts) {
	pitStopStrategy = new PitStopStrategy(ts);
}

void RaceStrategy::setDriverStrategy() {

	// TODO - implement RaceStrategy::setDriverStrategy
	throw "Not yet implemented";
void RaceStrategy::setDriverStrategy(TyreStrategy* ts) {
	driverStrategy = new DriverStrategy(ts);
	driverStrategy->setDriver(driver);
}

void RaceStrategy::setTyreStrategy() {
void RaceStrategy::setTyreStrategy(RaceTrack*  rt) {
	tyreStrategy = new TyreStrategy(rt);
}

	// TODO - implement RaceStrategy::setTyreStrategy
	throw "Not yet implemented";
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








