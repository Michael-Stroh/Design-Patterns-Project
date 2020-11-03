#include "Chassis.h"

//should never be used
Chassis::Chassis() 
{

}


Chassis::Chassis(float s, float h, float a, string b) : CarPart(s,h,a, "Chassis", b)
{


}

Chassis::~Chassis()
{
	
}


const float Chassis::INITIAL_SPEED = 7.5;

const float Chassis::INITIAL_SPEED_VARIANCE = 1.0;

const float Chassis::SPEED_CHANGE_VARIANCE = 0.5;

const float Chassis::INITIAL_ACCELERATION = 8.0;

const float Chassis::INITIAL_ACCELERATION_VARIANCE = 1.0;

const float Chassis::ACCELERATION_CHANGE_VARIANCE = 0.5;

const float Chassis::INITIAL_HANDLING = 8.0;

const float Chassis::INITIAL_HANDLING_VARIANCE = 1.0;

const float Chassis::HANDLING_CHANGE_VARIANCE = 0.5;

const float Chassis::MAX_ACCELERATION_VALUE = 15;

const  float Chassis::MAX_HANDLING_VALUE = 15;

const  float Chassis::MAX_SPEED_VALUE = 15;
