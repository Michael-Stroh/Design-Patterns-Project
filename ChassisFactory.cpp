#include "ChassisFactory.h"

ChassisFactory::ChassisFactory():CarPartFactory() {

	
}

ChassisFactory::~ChassisFactory() {

}

CarPart* ChassisFactory::createPart() {
	string brand = generateBrandName();
	float s = Chassis::INITIAL_SPEED + (rand()/10)*Chassis::INITIAL_SPEED_VARIANCE;
	float a = Chassis::INITIAL_ACCELERATION + (rand()/10)*Chassis::INITIAL_ACCELERATION_VARIANCE;
	float h = Chassis::INITIAL_HANDLING + (rand()/10)*Chassis::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Chassis(s,h,a, brand);
	return part;
}
