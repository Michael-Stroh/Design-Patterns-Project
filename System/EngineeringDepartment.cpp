#include "EngineeringDepartment.h"

//should never be used
EngineeringDepartment::EngineeringDepartment()
{
	simulationState = nullptr;
	remainingBudget = 0;
	budgetLimit = 0;
	this->budget = nullptr;
}


EngineeringDepartment::EngineeringDepartment(Simulation* state, Budget* budget, float budgetLimit)
{
	simulationState = state;
	this->budget = budget;
	this->budgetLimit = budgetLimit;
	remainingBudget = budget->getBudget();
}

EngineeringDepartment::EngineeringDepartment(Budget* budget, float budgetLimit)
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
	delete budget;
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

float EngineeringDepartment::getRemainingBalance()
{
	return remainingBudget;
}

void EngineeringDepartment::update()
{
	remainingBudget = budget->getBudget();
}

const float EngineeringDepartment::costPerSimulation = 100;