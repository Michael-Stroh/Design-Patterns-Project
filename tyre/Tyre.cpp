#include "Tyre.h"

Tyre::Tyre() {
	setDurability(0);
	setGrip(0);
	setPressure(0);
}

Tyre::Tyre( int StartDurability, int StartGrip, float StartPressure ):
		durability( StartDurability ), grip( StartGrip ), pressure( StartPressure ) {
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
