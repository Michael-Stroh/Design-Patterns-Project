#include "CoolingSystem.h"

//Should never be used
CoolingSystem::CoolingSystem() 
{
	
}

CoolingSystem::CoolingSystem(float s, float h, float a, string b) : CarPart(s,h,a, "CoolingSystem", b)
{
	coolingRate = INITIAL_COOLINGRATE;
}

CoolingSystem::~CoolingSystem()
{

}

void CoolingSystem::setCoolingRate(float newCoolingRate)
{
	coolingRate = newCoolingRate;
}

float CoolingSystem::getCoolingRate()
{
	return CoolingRate;
}