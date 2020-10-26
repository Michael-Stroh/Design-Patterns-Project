#include "TyreType.h"

TyreType::TyreType() {
	this->durability = 0;
	this->grip = 0;
	this->pressure = 0;
}

TyreType::TyreType(int durability, int grip, float pressure) {
	this->durability = durability;
	this->grip = grip;
	this->pressure = pressure;
}

TyreType::~TyreType()
{
	delete this;
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
