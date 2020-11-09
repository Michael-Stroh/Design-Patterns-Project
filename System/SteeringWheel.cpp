#include "SteeringWheel.h"

//should never be used
SteeringWheel::SteeringWheel()
{
	
}

SteeringWheel::SteeringWheel(float s, float h, float a, string b) : CarPart(s, h, a, "SteeringWheel", b)
{
	
}

SteeringWheel::~SteeringWheel()
{
	
}

const  float SteeringWheel::INITIAL_SPEED = 0.0;

const  float SteeringWheel::INITIAL_SPEED_VARIANCE = 0.0;

const  float SteeringWheel::SPEED_CHANGE_VARIANCE = 0.0;

const  float SteeringWheel::INITIAL_ACCELERATION = 0.0;

const  float SteeringWheel::INITIAL_ACCELERATION_VARIANCE = 0.0;

const  float SteeringWheel::ACCELERATION_CHANGE_VARIANCE = 0.0;

const  float SteeringWheel::INITIAL_HANDLING = 28.0;	//max value is effectively 30

const  float SteeringWheel::INITIAL_HANDLING_VARIANCE = 2.0;

const  float SteeringWheel::HANDLING_CHANGE_VARIANCE = 0.0;