#include "TyreType.h"

TyreType::TyreType() {
	// TODO - implement TyreType::TyreType
	throw "Not yet implemented";
}

TyreType::TyreType(int c, int parameter, float parameter2) {
	// TODO - implement TyreType::TyreType
	throw "Not yet implemented";
}

int TyreType::getDurability() {
	return this->durability;
}

void TyreType::setDurability(int durability) {
	this->durability = durability;
}

int TyreType::getGrip() {
	return this->grip;
}

void TyreType::setGrip(int c) {
	this->grip = c;
}

void TyreType::setPressure(float g) {
	this->pressure = g;
}

float TyreType::getPressure() {
	return this->pressure;
}
