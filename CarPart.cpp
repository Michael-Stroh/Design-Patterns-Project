#include "CarPart.h"

//To be safe, allocates default values to the part so
//that everything else should function.
CarPart::CarPart() {

	brand = "NoBrand";	//wont be used elsewhere so if we see a NoBrand branded part we know there is
						//a problem
	name = "GearBox";	//same reasoning as the brand
	handling = 10;
	speed = 1;
	acceleration = 0;
}

CarPart::CarPart(float s, float h, float a, string n, string b)
{
	speed = s;
	handling = h;
	acceleration = a;
	name = n;
	brand = b;
}

CarPart::CarPart( CarPart & part) {
	//Logger::setDebug(true);
	
	speed = part.speed;
	
	handling = part.handling;
	
	acceleration = part.acceleration;

	name = (part).name;

	brand = (part).brand;
	
	//Logger::debug("CarPart copy constructor", "Post setting of new variables");
	//Logger::setDebug(false);
}

CarPart *  CarPart::clone() {
	//Logger::setDebug(true);
	//Logger::debug("CarPart clone function:", this->name);
	CarPart* newPart = new CarPart(*this);
	//Logger::setDebug(false);

	return newPart;
}

//is subject to change should we decide to use a logger
void CarPart::print()
{
	Logger::magenta("Part ","-" + name);
	Logger::magenta("Brand ", "-" + brand);
	Logger::magenta("Speed Score ","-" + to_string(speed));
	Logger::magenta("Acceleration Score ", "-" + to_string(acceleration));
	Logger::magenta("Handling Score ", "-" + to_string(handling));
	
}

//Not a part of the Car interface class. Can be added to there if necessary, 
//for now, type cast the object to type CarPart to access this function.
string CarPart::getBrand() {
	return brand;
}

//realistically speaking this function will never be used.
//A new part of a different brand would be created.
void CarPart::setBrand(string newBrand) {
	brand = newBrand;
}

float CarPart::getHandling()
{
	return handling;
}

void CarPart::setHandling(float newHandling)
{
	handling = newHandling;
}

float CarPart::getSpeed()
{
	return speed;
}

void CarPart::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

float CarPart::getAcceleration()
{
	return acceleration;
}

void CarPart::setAcceleration(float newAcceleration)
{
	acceleration = newAcceleration;
}

void CarPart::add(int index, CarPart* c)
{
	Logger::log("Obselete Function Usage in CarPart", "Part of type " + name + "has no use for add function");
}

void CarPart::remove(int index)
{
	Logger::log("Obselete Function Usage in CarPart", "Part of type " + name + "has no use for remove function");
}

PartState* CarPart::createState()
{
	PartState* state = new PartState(acceleration, handling, speed);
	return state;
}

//state will not be deleted here. Will be deleted in carComposite class.
void CarPart::setState(PartState* state)
{
	this->acceleration = state->getAcceleration();
	this->handling = state->getHandling();
	this->speed = state->getSpeed();
}