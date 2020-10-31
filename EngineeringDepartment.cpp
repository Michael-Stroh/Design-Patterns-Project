#include "EngineeringDepartment.h"

//should never be used
EngineeringDepartment::EngineeringDepartment() 
{
	simulationState = nullptr;
	remainingBudget = nullptr;
	budgetLimit = 0;
}


EngineeringDepartment::EngineeringDepartment(Simulation* state,Budget * budget, float budgetLimit)
{
	simulationState = state;
	remainingBudget = budget;
	this->budgetLimit = budgetLimit;
}

EngineeringDepartment::EngineeringDepartment(Budget * budget, float budgetLimit)
{
	simulationState = new AccelerationSimulation();
	remainingBudget = budget;
	this->budgetLimit = budgetLimit;
}

EngineeringDepartment::~EngineeringDepartment() 
{
	delete simulationState;
	simulationState = nullptr;
}

void EngineeringDepartment::updateBudgetLimit(float newBudgetLimit) 
{
	budgetLimit = newBudgetLimit;
}

float EngineeringDepartment::getBudgetLimit()
{
	return budgetLimit;
}

