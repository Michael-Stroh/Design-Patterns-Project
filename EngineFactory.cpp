#include "EngineFactory.h"

EngineFactory::EngineFactory() {
	
}

EngineFactory::~EngineFactory()
{

}

CarPart* EngineFactory::createPart() 
{
	string brand = generateBrandName();
	float s = Engine::INITIAL_SPEED + generateRandomFraction()*Engine::INITIAL_SPEED_VARIANCE;
	float a = Engine::INITIAL_ACCELERATION + generateRandomFraction()  *Engine::INITIAL_ACCELERATION_VARIANCE;
	float h = Engine::INITIAL_HANDLING + generateRandomFraction()*Engine::INITIAL_HANDLING_VARIANCE;
	CarPart * part = new Engine(s,h,a, brand);
	return part;
}


