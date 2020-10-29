#include "ElectronicFactory.h"

ElectronicFactory::ElectronicFactory(): CarPartFactory() {

	
}

ElectronicFactory::~ElectronicFactory() {

}

CarPart* ElectronicFactory::createPart() {
	string brand = generateBrandName();
	float s = Electronics::INITIAL_SPEED + (rand()/10)*Electronics::INITIAL_SPEED_VARIANCE;
	float a = Electronics::INITIAL_ACCELERATION + (rand()/10)*Electronics::INITIAL_ACCELERATION_VARIANCE;
	float h = Electronics::INITIAL_HANDLING + (rand()/10)*Electronics::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Electronics(s,h,a, brand);
	return part;
	
}
