#include "ElectronicsDepartment.h"

//should not be used
ElectronicsDepartment::ElectronicsDepartment(): EngineeringDepartment() {


}

ElectronicsDepartment::ElectronicsDepartment(Budget * budget, float budgetLimit) : EngineeringDepartment(budget, budgetLimit)
{
	simulationState = new AccelerationSimulation();
}

ElectronicsDepartment::ElectronicsDepartment(Simulation * state, Budget * budget, float budgetLimit) : EngineeringDepartment(state, budget, budgetLimit)
{

}


ElectronicsDepartment::~ElectronicsDepartment() {

	delete simulationState;
}

void ElectronicsDepartment::runSimulation(CarComposite * car) 
{
	if (remainingBudget < budgetLimit + costPerSimulation) //if amount remaining smaller than our limit plust the cost for a simulation
		return;
	else
	{
		remainingBudget -= costPerSimulation;
		budget->setBudget(remainingBudget);
		budget->notifyAll();
	}

	CarPart* electronics = car->getPart(ELECTRONICS);
	float variances[] = { Electronics::ACCELERATION_CHANGE_VARIANCE,
						 Electronics::HANDLING_CHANGE_VARIANCE,
						  Electronics::SPEED_CHANGE_VARIANCE
	};
	float max[] = { Electronics::MAX_ACCELERATION_VALUE,
						 Electronics::MAX_HANDLING_VALUE,
						  Electronics::MAX_SPEED_VALUE

	};

	CarPart* potentialElectronics = simulationState->simulate(electronics, variances, max);


	float originalAggregate = electronics->getAcceleration() + electronics->getHandling() + electronics->getSpeed();
	float newAggregate = potentialElectronics->getAcceleration() + potentialElectronics->getHandling() + potentialElectronics->getSpeed();

	if (originalAggregate >= newAggregate) //old part is better
	{
		delete potentialElectronics;
	}
	else	//new part is better
	{
		car->remove(ELECTRONICS);
		car->add(ELECTRONICS, potentialElectronics);
	}

	Simulation* nextState = simulationState->getNextState();
	delete simulationState;
	simulationState = nextState;
	
}
