#include "RaceStrategy.h"

RaceStrategy::RaceStrategy() {
	// TODO - implement RaceStrategy::RaceStrategy
	throw "Not yet implemented";
}

void RaceStrategy::setPitCrewStrategy() {
	pitCrewStrategy = new pitCrewStrategy();
	// TODO - implement RaceStrategy::setPitCrewStrategy
}

void RaceStrategy::setDriverStrategy() {
	driverStrategy = new DriverStrategy();
	// TODO - implement RaceStrategy::setDriverStrategy
}

void RaceStrategy::setTyreStrategy() {
	tyreStrategy = new TyreStrategy();
	// TODO - implement RaceStrategy::setTyreStrategy
}
