#include "SteeringFactory.h"

SteeringFactory::SteeringFactory(): CarPartFactory() {

	
}

SteeringFactory::~SteeringFactory() {

}

CarPart* SteeringFactory::createPart() {

	string brand = generateBrandName();
	float s = SteeringWheel::INITIAL_SPEED + (rand()/10)*SteeringWheel::INITIAL_SPEED_VARIANCE;
	float a = SteeringWheel::INITIAL_ACCELERATION + (rand()/10)*SteeringWheel::INITIAL_ACCELERATION_VARIANCE;
	float h = SteeringWheel::INITIAL_HANDLING + (rand()/10)*SteeringWheel::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new SteeringWheel(s,h,a, brand);
	return part;
}
