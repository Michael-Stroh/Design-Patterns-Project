#include "BodyFactory.h"

BodyFactory::BodyFactory(): CarPartFactory() {

	
}

BodyFactory::~BodyFactory() {

	
}

CarPart* BodyFactory::createPart() {
	//Aerodynamics is set in the Constructor of the Body. May move, may stay there
	string brand = generateBrandName();
	float s = Body::INITIAL_SPEED + generateRandomFraction()*Body::INITIAL_SPEED_VARIANCE;
	float a = Body::INITIAL_ACCELERATION + generateRandomFraction()*Body::INITIAL_ACCELERATION_VARIANCE;
	float h = Body::INITIAL_HANDLING + generateRandomFraction()*Body::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Body(s,h,a, brand);
	return part;
}
