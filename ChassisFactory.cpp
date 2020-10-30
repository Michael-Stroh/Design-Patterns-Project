#include "ChassisFactory.h"

ChassisFactory::ChassisFactory():CarPartFactory() {

	
}

ChassisFactory::~ChassisFactory() {

}

CarPart* ChassisFactory::createPart() {
	string brand = generateBrandName();
	float s = Chassis::INITIAL_SPEED + generateRandomFraction()*Chassis::INITIAL_SPEED_VARIANCE;
	float a = Chassis::INITIAL_ACCELERATION + generateRandomFraction()*Chassis::INITIAL_ACCELERATION_VARIANCE;
	float h = Chassis::INITIAL_HANDLING + generateRandomFraction()*Chassis::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Chassis(s,h,a, brand);
	return part;
}
