#include "CarComposite.h"

//The default constructor. Sets all parts to nullptr. Adding of parts
//Will be handled By CarBuilder Class
CarComposite::CarComposite() {
	Logger::setDebug(true);
	Logger::debug("Default Constructor of CarComposite", "");
	Logger::setDebug(false);
	for(int i=0; i<NUMPARTS; ++i)
			carParts.push_back(nullptr);
	fuel = 0;
}

//The copy constructor, it clones every single part
//of the passed in car and adds them to itself.
CarComposite::CarComposite(const CarComposite& c) {

	for (int i = 0; i < NUMPARTS; ++i)
	{
		//Logger::setDebug(true);
		Logger::debug("CarComposite Clone Function:", to_string(i));
		CarPart* oldPart = c.getPart(i);
		CarPart * part = oldPart->clone();
		carParts.push_back(part);
		//Logger::setDebug(false);
	}
	fuel = 0;

}

//Deallocates the memory of all parts
//that this object owns.
CarComposite::~CarComposite()
{
	for(int i=0; i<NUMPARTS; ++i)
		delete carParts[i];
}

//Uses the copy constructor to create a new CarComposite Object
Car * CarComposite::clone() {
	
	return new CarComposite(*this);
}

//is subject to change depending on whether
//or not we use a logger.
void CarComposite::print() {

	Logger::magenta("Printing the summary of this CarComposite", "");
	for (int i = 0; i < carParts.size(); ++i)
	{
		carParts[i]->print();
		cout << endl;
	}
}

//should be used in conjunction with remove
void CarComposite::add(int index, CarPart * part) {
	if(index <0 || index >= NUMPARTS)
		throw "CarComposite::add; index out of bounds";
	else
	{
		if(carParts[index] != nullptr)	//an extra check to avoid memory leaks
			delete carParts[index];
		carParts[index] = part;
	}
}


void CarComposite::remove(int index) {
	if(index <0 || index >= NUMPARTS)
		throw "CarComposite::remove; index out of bounds";
	else
	{
		delete carParts[index];
		carParts[index] = nullptr;
	}
}

CarMemento* CarComposite::createCarMemento() {

	vector<PartState*> vec;
	for (int i = 0; i < NUMPARTS; ++i)
	{
		vec.push_back(carParts[i]->createState());
	}
	CarMemento* mem = new CarMemento();
	mem->setState(vec);
	return mem;
}

//seems simple and elegant.
void CarComposite::setCarMemento( CarMemento* memento ) {

	for (int i = 0; i < NUMPARTS; ++i)
	{
		carParts[i]->setState(memento->getState()[i]);
	}
	delete memento;
	memento = nullptr;
}


float CarComposite::getHandling()
{
	float handlingAggregate = 0;
	for(int i=0; i<carParts.size(); ++i)
		handlingAggregate += carParts[i]->getHandling();

	return handlingAggregate;
}

void CarComposite::setHandling(float newHandling)
{
	Logger::log("Obselete Function Usage in CarComposite", "SetHandling should be called on an individual component, not the car itself");
}

float CarComposite::getSpeed()
{
	float speedAggregate = 0;
	for(int i=0; i<carParts.size(); ++i)
		speedAggregate += carParts[i]->getSpeed();

	Body* b = (Body*)(this->getPart(BODY));

	return speedAggregate * b->getAerodynamicMultiplier();
}

void CarComposite::setSpeed(float newSpeed)
{
	Logger::log("Obselete Function Usage in CarComposite", "SetSpeed should be called on an individual component, not the car itself");
}

float CarComposite::getAcceleration()
{
	float accelerationAggregate = 0;
	for(int i=0; i<carParts.size(); ++i)
		accelerationAggregate += carParts[i]->getAcceleration();

	return accelerationAggregate;
}

void CarComposite::setAcceleration(float newAcceleration)
{
	Logger::log("Obselete Function Usage in CarComposite", "setAcceleration should be called on an individual component, not the car itself");
}


CarPart * CarComposite::getPart(int index) const
{
	if (index < 0 || index >= NUMPARTS)
		throw "CarComposite::get : index out of bounds error.";
	else
	{
		return carParts[index];
	}
}

void CarComposite::runLap(int difficulty)
{
	Engine* e = (Engine*)(this->getPart(ENGINE));
	CoolingSystem* c = (CoolingSystem*)(this->getPart(COOLINGSYSTEM));
	float coolingRate = c->getCoolingRate();
	float currentTemp = e->getTemperature();
	float maxTemp = Engine::MAX_TEMP;
	float newTemp;

	switch (difficulty)
	{
		//Case 0 means only cool down the car
		case 0:
			newTemp = currentTemp - coolingRate;
			if (newTemp < Engine::INITIAL_TEMPERATURE)
				e->setTemperature(Engine::INITIAL_TEMPERATURE);
			else { e->setTemperature(newTemp); }
			break;

		//case 1 means heat and cool down the car
		case 1:
			newTemp = currentTemp - coolingRate + Engine::TEMPRETURE_INCREMENT_DECREMENT;
			if (newTemp < Engine::INITIAL_TEMPERATURE)
				e->setTemperature(Engine::INITIAL_TEMPERATURE);
			else if (newTemp > Engine::MAX_TEMP)
				e->setTemperature(Engine::MAX_TEMP);
			else e->setTemperature(newTemp);
			break;

		//case 2 means only heat the car
		case 2:
			newTemp = currentTemp + Engine::TEMPRETURE_INCREMENT_DECREMENT;
			if (newTemp < Engine::INITIAL_TEMPERATURE)
				e->setTemperature(Engine::INITIAL_TEMPERATURE);
			else if (newTemp > Engine::MAX_TEMP)
				e->setTemperature(Engine::MAX_TEMP);
			else e->setTemperature(newTemp);

			break;
	}
	
}

void CarComposite::resetAfterRace()
{
	Engine* e = (Engine*)(this->getPart(ENGINE));
	e->setTemperature(Engine::INITIAL_TEMPERATURE);
}

float CarComposite::getFuel()
{
	return fuel;
}

void CarComposite::setFuel(float newFuel)
{
	fuel = newFuel;
}

const int CarComposite::NUMPARTS = 9;