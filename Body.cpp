#include "Body.h"

Body::Body() 
{
	aeroDynamicMultiplier = INITIAL_AERODYNAMICS * (rand() / 10) * INITAL_AERODYNAMICS_VARIANCE;
}

Body::Body(float s, float h, float a, string b) :CarPart(s, h, a, "Body", b)
{
	aeroDynamicMultiplier = INITIAL_AERODYNAMICS * (rand()/10)* INITAL_AERODYNAMICS_VARIANCE;
}

Body::~Body()
{

}

float Body::getAerodynamicMultiplier()
{
	return aeroDynamicMultiplier;
}

void Body::setAeroDynamicMultiplier(float newAeroDynamicMultiplier)
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

const  float Body::INITAL_AERODYNAMICS_VARIANCE = 0.02;

const  float Body::AERODYNAMICS_VARIANCE = 0.08;

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