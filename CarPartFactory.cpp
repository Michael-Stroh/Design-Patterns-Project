#include "CarPartFactory.h"

CarPartFactory::CarPartFactory()
{
	
}

CarPartFactory::~CarPartFactory()
{

}

//may need to test that this doesnt generate predictable names
string CarPartFactory::generateBrandName()
{
	srand(time(0));
	return brands[ rand() % numBrands];
}