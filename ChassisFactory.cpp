#include "ChassisFactory.h"

ChassisFactory::ChassisFactory():CarPartFactory() {

	
}

ChassisFactory::~ChassisFactory() {

}

CarPart* ChassisFactory::createPart() {
	string brand = generateBrandName();
	float s = chassis::INITIAL_SPEED + (rand()/10)*chassis::INITIAL_SPEED_VARIANCE;
	float a = chassis::INITIAL_ACCELERATION + (rand()/10)*chassis::INITIAL_ACCELERATION_VARIANCE;
	float h = chassis::INITIAL_HANDLING + (rand()/10)*chassis::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new chassis(s,h,a, brand);
	return part;
}
