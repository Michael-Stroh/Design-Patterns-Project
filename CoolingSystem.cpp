#include "CoolingSystem.h"

//Should never be used
CoolingSystem::CoolingSystem() 
{
	coolingRate = INITIAL_COOLINGRATE;
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
	return coolingRate;
}


const float CoolingSystem::INITIAL_COOLINGRATE = 0.9;

const float CoolingSystem::INITIAL_COOLINGVARIANCE = 0.2;

const float CoolingSystem::COOLINGRATE_CHANGE_VARIANCE = 0.1;

const float CoolingSystem::INITIAL_SPEED = 0.0;

const float CoolingSystem::INITIAL_SPEED_VARIANCE = 0.0;

const float CoolingSystem::SPEED_CHANGE_VARIANCE = 0.0;

const float CoolingSystem::INITIAL_ACCELERATION = 0.0;

const  float CoolingSystem::INITIAL_ACCELERATION_VARIANCE = 0.0;

const  float CoolingSystem::ACCELERATION_CHANGE_VARIANCE = 0.0;

const  float CoolingSystem::INITIAL_HANDLING = 0.0;

const  float CoolingSystem::INITIAL_HANDLING_VARIANCE = 0.0;

const  float CoolingSystem::HANDLING_CHANGE_VARIANCE = 0.0;