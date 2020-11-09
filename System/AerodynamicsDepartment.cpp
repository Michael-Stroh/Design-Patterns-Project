#include "AerodynamicsDepartment.h"

AerodynamicsDepartment::AerodynamicsDepartment(): EngineeringDepartment() {

}

AerodynamicsDepartment::AerodynamicsDepartment(Budget * budget, float budgetLimit ): EngineeringDepartment( budget, budgetLimit ) 
{

	simulationState = new WindTunnel();
}

AerodynamicsDepartment::AerodynamicsDepartment(Simulation * state, Budget* budget, float budgetLimit) : EngineeringDepartment(state, budget, budgetLimit)
{
	simulationState = state;

}

AerodynamicsDepartment::~AerodynamicsDepartment()
{
	delete simulationState;
}


void AerodynamicsDepartment::runSimulation(CarComposite * car) {

	if (remainingBudget < budgetLimit + costPerSimulation) //if amount remaining smaller than our limit plust the cost for a simulation
		return;
	else
	{
		remainingBudget -= costPerSimulation;
		budget->setBudget(remainingBudget);
		budget->notifyAll();
	}


	Body* body = (Body * ) (car->getPart(BODY));	//check the typeCasting since we need a Body pointer in particular
	float variances[] = { Body::AERODYNAMICS_VARIANCE
	};
	float max[] = { Body::MAX_AERODYNAMICS
	};

	Body* potentialBody = (Body * ) (simulationState->simulate(body, variances, max));
	Logger::debug("Potential Body aerodynamics: ", to_string(potentialBody->getAerodynamicMultiplier()));

	if (potentialBody->getAerodynamicMultiplier() <= body->getAerodynamicMultiplier())
	{
		delete potentialBody;
	}
	else
	{
		car->remove(BODY);
		car->add(BODY, potentialBody);
	}

	//no need to change state since this Department will only ever use the wind tunnel.
}
