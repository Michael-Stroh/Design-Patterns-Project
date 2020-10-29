#include "Body.h"

Body::Body() 
{
	
}

Body::Body(float s, float h, float a, string b) :CarPart(s, h, a, "Body", b)
{
	aeroDynamicMultiplier = INITIAL_AERODYNAMICS * (rand()/10)*INITIAL_AERODYNAMICS_VARIANCE;
}

Body::~Body()
{

}