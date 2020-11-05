#include "EngineeringDepartment.h"

//should never be used
EngineeringDepartment::EngineeringDepartment() 
{
	simulationState = nullptr;
	remainingBudget = 0;
	budgetLimit = 0;
	this->budget = nullptr;
}


EngineeringDepartment::EngineeringDepartment(Simulation* state,Budget * budget, float budgetLimit)
{
	simulationState = state;
	this->budget = budget;
	this->budgetLimit = budgetLimit;
	remainingBudget = budget->getBudget();
}

EngineeringDepartment::EngineeringDepartment(Budget * budget, float budgetLimit)
{
	simulationState = new AccelerationSimulation();
	this->budget = budget;
	this->budgetLimit = budgetLimit;
	remainingBudget = budget->getBudget();
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

void EngineeringDepartment::updateRemainingBudget(float newRemainingBudget)
{
	remainingBudget = newRemainingBudget;
}

void EngineeringDepartment::setBudget(Budget* budget)
{
	if (this->budget != nullptr)
		delete this->budget;
	this->budget = budget;
}

const float EngineeringDepartment::costPerSimulation = 100; 