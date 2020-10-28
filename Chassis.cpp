#include "Chassis.h"

//should never be used
Chassis::Chassis() 
{

}


Chassis::Chassis(float s, float h, float a, string b) : CarPart(s,h,a, "Chassis", b)
{


}

Chassis:~Chassis()
{
	
}