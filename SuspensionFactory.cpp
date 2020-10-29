#include "SuspensionFactory.h"

SuspensionFactory::SuspensionFactory(): CarPartFactory() {



SuspensionFactory::~SuspensionFactory() {

}


CarPart* SuspensionFactory::createPart() {

	string brand = generateBrandName();
	float s = Suspension::INITIAL_SPEED + (rand()/10)*Suspension::INITIAL_SPEED_VARIANCE;
	float a = Suspension::INITIAL_ACCELERATION + (rand()/10)*Suspension::INITIAL_ACCELERATION_VARIANCE;
	float h = Suspension::INITIAL_HANDLING + (rand()/10)*Suspension::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Suspension(s,h,a, brand);
	return part;
}