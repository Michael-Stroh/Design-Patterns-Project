#include "Electronics.h"

//should never be used
Electronics::Electronics() {
	
}

Electronics::Electronics(float s, float h, float a, string b) : CarPart(s, h,a, "Electronics", b)
{

}

CarPart::~CarPart()
{

}
