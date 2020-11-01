#include "SpeedSimulation.h"

SpeedSimulation::SpeedSimulation(): Simulation() {

	
}

SpeedSimulation::~SpeedSimulation()
{

}

CarPart* SpeedSimulation::simulate(CarPart* carPart, float variance[], float max[])
{
	CarPart* proposedPart = carPart->clone();
	float change = generateRandomFraction() * variance[2];
	if (generateRandomFraction() < 0)
		change *= -1;
	change += carPart->getSpeed();
	if (change <= max[2])
		proposedPart->setSpeed(change);

	return proposedPart;
}

void SpeedSimulation::simulate(Driver* driver)
{

}


Simulation* SpeedSimulation::getNextState()
{
	return new SpeedSimulation();
}
