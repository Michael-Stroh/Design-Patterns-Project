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

	Body* body = (Body * ) (car->getPart(BODY));	//check the typeCasting since we need a Body pointer in particular
	float variances[] = { Body::AERODYNAMICS_VARIANCE
	};
	float max[] = { Body::MAX_AERODYNAMICS
	};

	Body* potentialBody = (Body * ) (simulationState->simulate(body, variances, max));
	Logger::setDebug(true);
	Logger::debug("Potential Body aerodynamics: ", to_string(potentialBody->getAerodynamicMultiplier()));
	Logger::setDebug(false);

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
