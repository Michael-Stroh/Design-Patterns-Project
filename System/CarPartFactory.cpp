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

float CarPartFactory::generateRandomFraction()
{
	float randNum =( (rand() % 100) / 100.0);
	if ((rand() % 100) / 100.0 < 0.5)
		randNum *= -1;
	return randNum;
}


const string CarPartFactory::brands[] = { "Volvo", "BMW", "Ferrari", "Mercedes", "McClaren", "Alfa Romeo", "RedBull" };

/**
	@brief The number of elements in the brands array
*/
const  int CarPartFactory::numBrands = 7;