#include "PartState.h"

PartState::PartState(float acceleration, float handling, float speed, float coolingRate)
{
	this->acceleration = acceleration;
	this->handling = handling;
	this->speed = speed;
	this->coolingRate = coolingRate; //value will be -1 if this part need not worry about this
}

float PartState::getAcceleration()
{
	return acceleration;
}

float PartState::getHandling()
{
	return handling;
}

float PartState::getSpeed()
{
	return speed;
}

float PartState::getCoolingRate()
{
	return coolingRate;
}