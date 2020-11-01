#include "WindTunnel.h"

WindTunnel::WindTunnel(): Simulation() {

	
}

WindTunnel::~WindTunnel() 
{

}


int WindTunnel::getUsage() {

	return this->usage;
}

void WindTunnel::setUsage( int used ) {

	usage = used;
}

int WindTunnel::getAllowedUsage() {

	return usageAllowed;
}

void WindTunnel::setAllowedUsage( int allowedUsed ) {

	usageAllowed = allowedUsed;
}

CarPart* WindTunnel::simulate(CarPart* body, float variance[], float max[])
{
	Body* tempBody = (Body*)body;
	Body* potentialBody = (Body * )body->clone();

	float newAero = generateRandomFraction() * variance[0];
	if (generateRandomFraction() < 0)
		newAero *= -1;
	newAero += tempBody->getAerodynamicMultiplier();
	if (newAero <= max[0])
		potentialBody->setAeroDynamicMultiplier(newAero);

	return potentialBody;
}

void WindTunnel::simulate(Driver* driver)
{

}

Simulation* WindTunnel::getNextState()
{
	return new WindTunnel();
}