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

const  float SteeringWheel::INITIAL_HANDLING = 55.0;

const  float SteeringWheel::INITIAL_HANDLING_VARIANCE = 5.0;

const  float SteeringWheel::HANDLING_CHANGE_VARIANCE = 3.0;