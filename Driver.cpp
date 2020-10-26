#include "Driver.h"

Driver::Driver() {

	// TODO - implement Driver::Driver
	throw "Not yet implemented";
}

Driver::Driver( string DriverName ): name(  DriverName ) {

	// TODO - implement Driver::Driver
	throw "Not yet implemented";
}

Driver::~Driver() {

	// TODO - implement Driver::Driver
	throw "Not yet implemented";
}

Driver::Driver( string DriverName, int DriverAggression, float move ):
			name( DriverName ), aggression( DriverAggression ), specialMove( move ) {

	// TODO - implement Driver::Driver
	throw "Not yet implemented";
}

void Driver::setName( string DriverName ) {

	this->name = DriverName;
}

int Driver::getAggression() {

	return this->aggression;
}

void Driver::setAggression( int DriverAggression ) {

	this->aggression = DriverAggression;
}

float Driver::getSpecialMove() {

	return this->specialMove;
}

void Driver::setSpecialMove( float move ) {

	this->specialMove = move;
}