#include "BodyFactory.h"

BodyFactory::BodyFactory(): CarPartFactory() {

	
}

BodyFactory::~BodyFactory() {

	
}

CarPart* BodyFactory::createPart() {
	//Aerodynamics is set in the Constructor of the Body. May move, may stay there
	string brand = generateBrandName();
	float s = Body::INITIAL_SPEED + (rand()/10)*Body::INITIAL_SPEED_VARIANCE;
	float a = Body::INITIAL_ACCELERATION + (rand()/10)*Body::INITIAL_ACCELERATION_VARIANCE;
	float h = Body::INITIAL_HANDLING + (rand()/10)*Body::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Body(s,h,a, brand);
	return part;
}
