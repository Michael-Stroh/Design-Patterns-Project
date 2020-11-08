#include "WindTunnel.h"

WindTunnel::WindTunnel(): Simulation() {

	usageAllowed = 100;
	usage = 0;
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

	if (usage >= usageAllowed)
		return potentialBody;
	else usage++;

	float newAero =  generateRandomFraction() * variance[0];
	if (generateRandomFraction() < 0.49)
		newAero *= -1;
	newAero += tempBody->getAerodynamicMultiplier();
	//Logger::debug("WindTUnnel; simulate newAero: ", to_string(newAero));

	if (newAero <= max[0])
		potentialBody->setAerodynamicMultiplier(newAero);

	return potentialBody;
}

void WindTunnel::simulate(Driver* driver)
{

}

Simulation* WindTunnel::getNextState()
{
	return new WindTunnel();
}