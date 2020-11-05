#include "AccelerationSimulation.h"

AccelerationSimulation::AccelerationSimulation() {

	
}

AccelerationSimulation::~AccelerationSimulation()
{
	
}

void AccelerationSimulation::simulate(Driver* driver)
{

}

CarPart* AccelerationSimulation::simulate(CarPart* carPart, float variance[], float max[])
{
	CarPart* proposedPart = carPart->clone();
	float change = generateRandomFraction() * variance[0];
	if (generateRandomFraction() < 0)
		change *= -1;
	change += carPart->getAcceleration();
	if(change <= max[0])
		proposedPart->setAcceleration(change);

	return proposedPart;
}

Simulation* AccelerationSimulation::getNextState()
{
	return new HandlingSimulation();
}
