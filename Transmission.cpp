#include "Transmission.h"

//should never be used
Transmission::Transmission()
{
	
}

Transmission::Transmission(float s, float h, float a, string b) : CarPart(s,h,a, "Transmission", b)
{
	
}

Transmission::~Transmission()
{

}


const  float Transmission::INITIAL_SPEED = 8.5;

const  float Transmission::INITIAL_SPEED_VARIANCE = 1.5;

const  float Transmission::SPEED_CHANGE_VARIANCE = 0.5;

const  float Transmission::INITIAL_ACCELERATION = 15.0;

const  float Transmission::INITIAL_ACCELERATION_VARIANCE = 3.0;

const  float Transmission::ACCELERATION_CHANGE_VARIANCE = 1.5;

const  float Transmission::INITIAL_HANDLING = 0.0;

const  float Transmission::INITIAL_HANDLING_VARIANCE = 0.0;

const  float Transmission::HANDLING_CHANGE_VARIANCE = 0.0;