#include "Suspension.h"


//should never be used
Suspension::Suspension() 
{
	
}

Suspension::Suspension(float s, float h, float a, string b) : CarPart(s, h, a, "Suspension", b)
{

}

Suspension::~Suspension()
{

}

const float Suspension::INITIAL_SPEED = 8.0;

const  float Suspension::INITIAL_SPEED_VARIANCE = 1.0;

const  float Suspension::SPEED_CHANGE_VARIANCE = 0.5;

const  float Suspension::INITIAL_ACCELERATION = 8.0;

const  float Suspension::INITIAL_ACCELERATION_VARIANCE = 1.0;

const  float Suspension::ACCELERATION_CHANGE_VARIANCE = 0.5;

const  float Suspension::INITIAL_HANDLING = 8.0;

const  float Suspension::INITIAL_HANDLING_VARIANCE = 1.0;

const float Suspension::HANDLING_CHANGE_VARIANCE = 0.5;