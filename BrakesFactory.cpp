#include "BrakesFactory.h"

BrakesFactory::BrakesFactory(): CarPartFactory() {


}

BrakesFactory::~BrakesFactory() {

	
}

CarPart* BrakesFactory::createPart() {

	string brand = generateBrandName();
	float s = Brakes::INITIAL_SPEED + generateRandomFraction()*Brakes::INITIAL_SPEED_VARIANCE;
	float a = Brakes::INITIAL_ACCELERATION + generateRandomFraction()*Brakes::INITIAL_ACCELERATION_VARIANCE;
	float h = Brakes::INITIAL_HANDLING + generateRandomFraction()*Brakes::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Brakes(s,h,a, brand);
	return part;
}

