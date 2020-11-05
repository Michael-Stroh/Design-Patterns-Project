#include "Tyre.h"

Tyre::Tyre() {

	// TODO - implement Tyre::Tyre
	throw "Not yet implemented";
}

Tyre::Tyre( int StartDurability, int StartGrip, float StartPressure ):
		durability( StartDurability ), grip( StartGrip ), pressure( StartPressure ) {

	// TODO - implement Tyre::Tyre
	throw "Not yet implemented";
}

Tyre::~Tyre() {

}

int Tyre::getDurability() {

	return this->durability;
}

void Tyre::setDurability( int StartDurability ) {

	this->durability = StartDurability;
}

int Tyre::getGrip() {

	return this->grip;
}

void Tyre::setGrip( int StartGrip ) {

	this->grip = StartGrip;
}

float Tyre::getPressure() {

	return this->pressure;
}

void Tyre::setPressure( float StartPressure ) {

	this->pressure = StartPressure;
}

void Tyre::setType( string typeTyre ) {

	type = typeTyre;
}

string Tyre::getType() {

	return type;
}
