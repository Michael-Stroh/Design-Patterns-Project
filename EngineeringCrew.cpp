#include "EngineeringCrew.h"

EngineeringCrew::EngineeringCrew() 
{

	budget = new Budget();		//actual amount gets
	//Build car n shit
	departments[0] = new EngineDepartment(budget, 0);
	departments[1] = new ElectronicsDepartment(budget, 0);
	departments[2] = new ChassisDepartment(budget, 0);
	departments[3] = new AerodynamicsDepartment(budget, 0);

	for (int i = 0; i < departments.size(); ++i)
		budget->attach(departments[0]);
}


EngineeringCrew::~EngineeringCrew()
{
	for (int i = 0; i < departments.size(); ++i)
		budget->detach(departments[i]);
	delete budget;
	for (int i = 0; i < departments.size(); ++i)
		departments[i];
}

CarComposite* EngineeringCrew::getCar() {

	// TODO - implement EngineeringCrew::getCar
	throw "Not yet implemented";
}

void EngineeringCrew::setCar( Car* car ) {

	// TODO - implement EngineeringCrew::setCar
	throw "Not yet implemented";
}

CarComposite * EngineeringCrew::getNextSeasonCar() {

	// TODO - implement EngineeringCrew::getnextSeasonCar
	throw "Not yet implemented";
}

void EngineeringCrew::setNextSeasonCar( Car* car ) 
{

	
}

void EngineeringCrew::calculateBudget(int numGrandPrixs)
{
	float totalInitialBalance = numGrandPrixs * moneyPerGrandPrix;
	budget->setBudget(totalInitialBalance);
	budget->notifyAll();	
	for (int i = 0; i < departments.size(); ++i)
		departments[i]->updateBudgetLimit(totalInitialBalance - moneyPerGrandPrix);
}

void EngineeringCrew::updateDepartmentBudgets()
{
	for (int i = 0; i < departments.size(); ++i)
		departments[i]->updateBudgetLimit(departments[i]->getBudgetLimit() - moneyPerGrandPrix);
}

const float EngineeringCrew::moneyPerGrandPrix = 1000;