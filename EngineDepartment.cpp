#include "EngineDepartment.h"

EngineDepartment::EngineDepartment(): EngineeringDepartment() {

	
}

EngineDepartment::EngineDepartment(Budget * budget, float budgetLimit ): EngineeringDepartment( budget, budgetLimit )
{
	simulationState = new AccelerationSimulation();
}


EngineDepartment::EngineDepartment( Simulation* state, Budget * budget, float budgetLimit ): EngineeringDepartment( state, budget, budgetLimit ) {


}

EngineDepartment::~EngineDepartment()
{
	delete simulationState;
}

//Look into typeCasting, check for memory leaks!!
void  EngineDepartment::runSimulation(CarComposite * car) 
{
	Logger::setDebug(true);
	Logger::debug("Engine::department before paying", "remainingBudget + " + to_string(remainingBudget));

	if (remainingBudget < budgetLimit + costPerSimulation) //if amount remaining smaller than our limit plust the cost for a simulation
		return;
	else
	{
		remainingBudget -= costPerSimulation;
		budget->setBudget(remainingBudget);
		budget->notifyAll();
	}

	Logger::debug("Engine::department after paying", "remainingBudget + " + to_string(remainingBudget));

	CarPart* engine = car->getPart(ENGINE); 
	float variances[] = { Engine::ACCELERATION_CHANGE_VARIANCE,
						 Engine::HANDLING_CHANGE_VARIANCE,
						  Engine::SPEED_CHANGE_VARIANCE
						  };
	float max [] = { Engine::MAX_ACCELERATION_VALUE,
						 Engine::MAX_HANDLING_VALUE,
						  Engine::MAX_SPEED_VALUE

	};

	CarPart* potentialEngine = simulationState->simulate(engine, variances, max);


	float originalAggregate = engine->getAcceleration() + engine->getHandling() + engine->getSpeed();
	float newAggregate = potentialEngine->getAcceleration() + potentialEngine->getHandling() + potentialEngine->getSpeed();

	if (originalAggregate >= newAggregate) //old part is better
	{
		delete potentialEngine;
	}
	else	//new part is better
	{
		car->remove(ENGINE);
		car->add(ENGINE, potentialEngine);
	}

	Simulation * nextState = simulationState->getNextState();
	delete simulationState;
	simulationState = nextState;

}
