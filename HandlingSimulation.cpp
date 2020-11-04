#include "HandlingSimulation.h"

HandlingSimulation::HandlingSimulation(): Simulation()
{

	
}

HandlingSimulation::~HandlingSimulation() {

}

void HandlingSimulation::simulate(Driver* driver)
{

}


CarPart* HandlingSimulation::simulate(CarPart* carPart, float variance[], float max[])
{
	CarPart* proposedPart = carPart->clone();
	float change = generateRandomFraction() * variance[1];
	if (generateRandomFraction() < 0)
		change *= -1;
	change += carPart->getHandling();
	if (change <= max[1])
		proposedPart->setHandling(change);

	return proposedPart;
}

Simulation *  HandlingSimulation::getNextState()
{
	return new SpeedSimulation();
}
