#include "Simulation.h"

Simulation::Simulation() {

	
}

Simulation::~Simulation() {

}

float Simulation::generateRandomFraction()
{
	float randNum = ((rand() % 100) / 100.0) - ((rand() % 100) / 100.0);
	return randNum;
}