#include "EngineeringCrew.h"

EngineeringCrew::EngineeringCrew() 
{
	/*
		Builders and building the cars
	*/
	Logger::debug("EngineeringCrew::constructor", "");
	Logger::debug("EngineeringCrew::constructor", "making a carBuilder");
	builder = new CarBuilder();
	Logger::debug("EngineeringCrew::constructor", "making the car");
	car = builder->buildCar();
	Logger::debug("EngineeringCrew::constructor", "cloning the original car");
	nextSeasonCar = (CarComposite *)car->clone();
	
	/*
		Handling the Budget and the EngineeringDepartments
	*/
	budget = new Budget();		//actual amount gets
	
	departments.push_back(new EngineDepartment(budget, 0));
	departments.push_back(new ElectronicsDepartment(budget, 0));
	departments.push_back(new ChassisDepartment(budget, 0));
	departments.push_back(new AerodynamicsDepartment(budget, 0));

	for (int i = 0; i < departments.size(); ++i)
		budget->attach(departments[i]);
}


EngineeringCrew::~EngineeringCrew()
{
	delete builder;
	delete car;
	delete nextSeasonCar;
	for (int i = 0; i < departments.size(); ++i)
		budget->detach(departments[i]);
	delete budget;
	for (int i = 0; i < departments.size(); ++i)
		departments[i];
}

CarComposite* EngineeringCrew::getCar() {

	return car;
}

void EngineeringCrew::setCar( CarComposite * car ) {

	if (this->car != nullptr)
		delete this->car;

	this->car = car;
}

CarComposite * EngineeringCrew::getNextSeasonCar() {

	return nextSeasonCar;
}

void EngineeringCrew::setNextSeasonCar( CarComposite * car ) 
{
	if (this->nextSeasonCar != nullptr)
		delete this->nextSeasonCar;

	this->nextSeasonCar = car;
	
}

void EngineeringCrew::calculateBudget(int numGrandPrixs)
{
	float totalInitialBalance = numGrandPrixs * moneyPerGrandPrix;
	budget->setBudget(totalInitialBalance);
	budget->notifyAll();	

	for (int i = 0; i < departments.size(); ++i)
	{
		Logger::debug("EngineeringCrew::calulcate budget department " + i, to_string(departments[i]->getRemainingBalance()));
		
		departments[i]->updateBudgetLimit(totalInitialBalance);
	}
}

void EngineeringCrew::updateDepartmentBudgets()
{
	for (int i = 0; i < departments.size(); ++i)
		departments[i]->updateBudgetLimit(departments[i]->getBudgetLimit() - moneyPerGrandPrix);
}

void EngineeringCrew::prepareForNextRace()
{

	//Logger::debug("EngineeringCrew::prepareForNextRace", "IF there is an infinite loop it is here");
	while (budget->getBudget() > departments[0]->getBudgetLimit())	//TEST THIS!!!!
	{
		for (int i = 0; i < departments.size(); ++i)
			departments[i]->runSimulation(nextSeasonCar);
	}
}

const float EngineeringCrew::moneyPerGrandPrix = 1000;