#include "CoolingFactory.h"

CoolingFactory::CoolingFactory(): CarPartFactory() {

}

CoolingFactory::~CoolingFactory() {


}

CarPart* CoolingFactory::createPart() {
	string brand = generateBrandName();
	float s = CoolingSystem::INITIAL_SPEED + (rand()/10)*CoolingSystem::INITIAL_SPEED_VARIANCE;
	float a = CoolingSystem::INITIAL_ACCELERATION + (rand()/10)*CoolingSystem::INITIAL_ACCELERATION_VARIANCE;
	float h = CoolingSystem::INITIAL_HANDLING + (rand()/10)*CoolingSystem::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new CoolingSystem(s,h,a, brand);
	return part;
}
