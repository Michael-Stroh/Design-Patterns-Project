#include "CarComposite.h"

//The default constructor. Sets all parts to nullptr. Adding of parts
//Will be handled By CarBuilder Class
CarComposite::CarComposite() {
	Logger::setDebug(true);
	Logger::magenta("Default Constructor of CarComposite", "");
	Logger::setDebug(false);
	for(int i=0; i<NUMPARTS; ++i)
			carParts.push_back(nullptr);
}

//The copy constructor, it clones every single part
//of the passed in car and adds them to itself.
CarComposite::CarComposite(const CarComposite& c) {

	for(int i=0; i<NUMPARTS; ++i)
		carParts.push_back( ((CarComposite)c).getPart(i)->clone() );	//check that this typecasting works

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
	for(int i=0; i<carParts.size(); ++i)
		carParts[i]->print();

}

//should be used in conjunction with remove
void CarComposite::add(int index, Car * part) {
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

	// TODO - implement CarComposite::createCarMemento
	throw "Not yet implemented";
}

void CarComposite::setCarMemento( CarMemento* memento ) {

	// TODO - implement CarComposite::setCarMemento
	throw "Not yet implemented";
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

	return speedAggregate;
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


Car* CarComposite::getPart(int index)
{
	if (index < 0 || index >= NUMPARTS)
		throw "CarComposite::get : index out of bounds error.";
	else
	{
		return carParts[index];
	}
}

const int CarComposite::NUMPARTS = 9;