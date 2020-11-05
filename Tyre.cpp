#include "Tyre.h"

Tyre::Tyre(): durability( 0 ), grip( 0 ), pressure( 0 ) {

}

Tyre::Tyre( int StartDurability, int StartGrip, float StartPressure ):
		durability( StartDurability ), grip( StartGrip ), pressure( StartPressure ) {
}

Tyre::~Tyre() {

}

int Tyre::getDurability() const {

	return durability;
}

void Tyre::setDurability( int StartDurability ) {

	durability = StartDurability;
}

int Tyre::getGrip() const {

	return grip;
}

void Tyre::setGrip( int StartGrip ) {

	this->grip = StartGrip;
}

float Tyre::getPressure() const {

	return pressure;
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

