#include "RaceStrategy.h"


RaceStrategy::RaceStrategy(Driver* drive, RaceTrack* track) : rt(track), driver(drive) {

	setTyreStrategy(rt);
	setDriverStrategy(tyreStrategy);
	setPitStopStrategy(tyreStrategy);
}

RaceStrategy::~RaceStrategy() {

	delete rt;
	delete driver;
	delete pitStopStrategy;
	delete driverStrategy;
	delete tyreStrategy;
}

void RaceStrategy::setPitStopStrategy(TyreStrategy* strategy) {

	pitStopStrategy = new PitStopStrategy(strategy);
}


void RaceStrategy::setDriverStrategy(TyreStrategy* strategy) {

	driverStrategy = new DriverStrategy(strategy);
	driverStrategy->setDriver(driver);
	driverStrategy->decideStrategy();
}

void RaceStrategy::setTyreStrategy(RaceTrack* track) {

	tyreStrategy = new TyreStrategy(track);

}

DriverStrategy* RaceStrategy::getDriverStrategy() {

	return driverStrategy;
}


TyreStrategy* RaceStrategy::getTyreStrategy() {

	return tyreStrategy;
}

PitStopStrategy* RaceStrategy::getPitStopStrategy() {

	return pitStopStrategy;
}

void RaceStrategy::setDriver(Driver* drive) {

	driver = drive;
}

Driver* RaceStrategy::getDriver() {

	return driver;
}








