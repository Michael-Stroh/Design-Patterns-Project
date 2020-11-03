#include "Body.h"

//Important to avoid integer division when trying to generate a fraction 0-1.0
Body::Body() 
{
	float variance = (rand() % 100) / 100.0 * INITAL_AERODYNAMICS_VARIANCE;
	if (rand() % 100 < 50)
		variance *= -1;
	aeroDynamicMultiplier = INITIAL_AERODYNAMICS + variance;
}

Body::Body(float s, float h, float a, string b) :CarPart(s, h, a, "Body", b)
{
	float variance = (rand() % 100) / 100.0 * INITAL_AERODYNAMICS_VARIANCE;
	if (rand() % 100 < 50)
		variance *= -1;
	aeroDynamicMultiplier = INITIAL_AERODYNAMICS + variance;
}

Body::~Body()
{

}

Body::Body(Body& part)
{
	speed = part.speed;

	handling = part.handling;

	acceleration = part.acceleration;

	name = (part).name;

	brand = (part).brand;

	aeroDynamicMultiplier = part.aeroDynamicMultiplier;
}

CarPart* Body::clone()
{
	return new Body(*this);
}

float Body::getAerodynamicMultiplier()
{
	return aeroDynamicMultiplier;
}

void Body::setAerodynamicMultiplier(float newAeroDynamicMultiplier)
{
	aeroDynamicMultiplier = newAeroDynamicMultiplier;
}

PartState* Body::createState()
{
	PartState* state = new PartState(acceleration, handling, speed, -1, aeroDynamicMultiplier);
	return state;
}

//state will not be deleted here. Will be deleted in carComposite class.
void Body::setState(PartState* state)
{
	this->acceleration = state->getAcceleration();
	this->handling = state->getAcceleration();
	this->speed = state->getSpeed();
	this->aeroDynamicMultiplier = state->getAeroDynamicsMultiplier();
}

const  float Body::INITIAL_AERODYNAMICS = 0.65;

const  float Body::INITAL_AERODYNAMICS_VARIANCE = 0.05;

const  float Body::AERODYNAMICS_VARIANCE = 0.06;

const float Body::MAX_AERODYNAMICS = 1.0;

const  float Body::INITIAL_SPEED = 0.0;

const  float Body::INITIAL_SPEED_VARIANCE = 0.0;

const  float Body::SPEED_CHANGE_VARIANCE = 0.0;

const  float Body::INITIAL_ACCELERATION = 0.0;

const  float Body::INITIAL_ACCELERATION_VARIANCE = 0.0;

const  float Body::ACCELERATION_CHANGE_VARIANCE = 0.0;

const  float Body::INITIAL_HANDLING = 0.0;

const  float Body::INITIAL_HANDLING_VARIANCE = 0.0;

const  float Body::HANDLING_CHANGE_VARIANCE = 0.0;