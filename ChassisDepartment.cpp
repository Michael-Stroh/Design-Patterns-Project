#include "ChassisDepartment.h"

ChassisDepartment::ChassisDepartment() : EngineeringDepartment() {


}

ChassisDepartment::ChassisDepartment(Budget* budget, float budgetLimit) : EngineeringDepartment(budget, budgetLimit)
{


}


ChassisDepartment::ChassisDepartment(Simulation* state, Budget* budget, float budgetLimit) : EngineeringDepartment(state, budget, budgetLimit) {


}

ChassisDepartment::~ChassisDepartment()
{


}

void  ChassisDepartment::runSimulation(CarComposite* car)
{
	CarPart* Chassis = car->getPart(CHASSIS);
	float variances[] = { Chassis::ACCELERATION_CHANGE_VARIANCE,
						 Chassis::HANDLING_CHANGE_VARIANCE,
						  Chassis::SPEED_CHANGE_VARIANCE
	};
	float max[] = { Chassis::MAX_ACCELERATION_VALUE,
						 Chassis::MAX_HANDLING_VALUE,
						  Chassis::MAX_SPEED_VALUE

	};
	CarPart* potentialChassis = simulationState->simulate(Chassis, variances, max);


	float originalAggregate = Chassis->getAcceleration() + Chassis->getHandling() + Chassis->getSpeed();
	float newAggregate = potentialChassis->getAcceleration() + potentialChassis->getHandling() + potentialChassis->getSpeed();

	if (originalAggregate >= newAggregate) //old part is better
	{
		delete potentialChassis;
	}
	else	//new part is better
	{
		car->remove(CHASSIS);
		car->add(CHASSIS, potentialChassis);
	}

	Simulation* nextState = simulationState->getNextState();
	delete simulationState;
	simulationState = nextState;
}
