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


const  float Body::INITIAL_AERODYNAMICS = 0.65;

const  float Body::INITAL_AERODYNAMICS_VARIANCE = 0.02;

const  float Body::AERODYNAMICS_VARIANCE = 0.01;

const  float Body::INITIAL_SPEED = 55;

const  float Body::INITIAL_SPEED_VARIANCE = 5.0;

const  float Body::SPEED_CHANGE_VARIANCE = 2.0;

const  float Body::INITIAL_ACCELERATION = 55.0;

const  float Body::INITIAL_ACCELERATION_VARIANCE = 5.0;

const  float Body::ACCELERATION_CHANGE_VARIANCE = 2.0;

const  float Body::INITIAL_HANDLING = 0.0;

const  float Body::INITIAL_HANDLING_VARIANCE = 0.0;

const  float Body::HANDLING_CHANGE_VARIANCE = 0.0;