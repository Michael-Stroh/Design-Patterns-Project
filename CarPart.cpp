#include "CarPart.h"

CarPart::CarPart() {

	// TODO - implement CarPart::CarPart
	throw "Not yet implemented";
}

CarPart::CarPart( string CarName ): name( CarName ) {

}

CarPart::CarPart( string CarName, string BrandName, float accelerate, float handlingValue, float speedValue ):
		name( CarName ), brand( BrandName ), acceleration( accelerate ),
		handling( handlingValue ), speed( speedValue ) {

}

CarPart::CarPart( Car& Car ) {

	// TODO - implement CarPart::CarPart
	throw "Not yet implemented";
}

CarPart::CarPart( Tyre* type ): tyre( type ) {

	// TODO - implement CarPart::CarPart
	throw "Not yet implemented";
}


CarPart::~CarPart() {

}

Car *  CarPart::clone() {

	// TODO - implement CarPart::clone
	throw "Not yet implemented";
}

string CarPart::getName() {

	return name;
}

void CarPart::setName( string CarName ) {

	name = CarName;
}

string CarPart::getBrand() {

	return brand;
}

void CarPart::setBrand( string BrandName ) {

	brand = BrandName;
}

float CarPart::getHandling() {

	return handling;
}

void CarPart::setHandling( float handlingValue ) {

	handling = handlingValue;
}

float CarPart::getSpeed() {

	return speed;
}

void CarPart::setSpeed( float speedValue ) {

	speed = speedValue;
}

float CarPart::getAcceleration() {

	return acceleration;
}

void CarPart::setAcceleration( float accelerate ) {

	acceleration = accelerate;
}
