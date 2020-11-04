#include "Brakes.h"

//Should not be used
Brakes::Brakes() 
{
	
}

Brakes::Brakes(float s, float h, float a, string b) : CarPart(s,h,a, "Brakes", b)
{

}

Brakes::~Brakes()
{

}


const  float Brakes::INITIAL_SPEED = 0.0;

const  float Brakes::INITIAL_SPEED_VARIANCE = 0.0;

const  float Brakes::SPEED_CHANGE_VARIANCE = 0.0;

const  float Brakes::INITIAL_ACCELERATION = 0.0;

const  float Brakes::INITIAL_ACCELERATION_VARIANCE = 0.0;

const  float Brakes::ACCELERATION_CHANGE_VARIANCE = 0.0;

const  float Brakes::INITIAL_HANDLING = 28.0; //max value is effectively 30

const  float Brakes::INITIAL_HANDLING_VARIANCE = 2.0;

const  float Brakes::HANDLING_CHANGE_VARIANCE = 0.0;

