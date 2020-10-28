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

