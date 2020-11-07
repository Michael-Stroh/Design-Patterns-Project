#include "Electronics.h"

//should never be used
Electronics::Electronics() {
	
}

Electronics::Electronics(float s, float h, float a, string b) : CarPart(s, h,a, "Electronics", b)
{

}

Electronics::~Electronics()
{

}

CarPart::~CarPart()
{

}

const  float Electronics::INITIAL_SPEED = 7.5;

const  float Electronics::INITIAL_SPEED_VARIANCE = 1.0;

const  float Electronics::SPEED_CHANGE_VARIANCE = 0.5;

const  float Electronics::INITIAL_ACCELERATION = 7.5;

const  float Electronics::INITIAL_ACCELERATION_VARIANCE = 1.0;

const  float Electronics::ACCELERATION_CHANGE_VARIANCE = 0.5;

const  float Electronics::INITIAL_HANDLING = 11.0;

const  float Electronics::INITIAL_HANDLING_VARIANCE = 1.0;

const  float Electronics::HANDLING_CHANGE_VARIANCE = 1.0;

const float Electronics::MAX_ACCELERATION_VALUE = 10;

const  float Electronics::MAX_HANDLING_VALUE = 15;

const  float Electronics::MAX_SPEED_VALUE = 10;