#include "Engine.h"

//Should never be used
Engine::Engine() {
	temperature = INITIAL_TEMPERATURE;
}

Engine::Engine(float s, float h, float a, string b) : CarPart(s,h,a, "Engine", b)
{
	temperature = INITIAL_TEMPERATURE;
}

Engine::~Engine()
{
	
}

float Engine::getSpeed()
{
	return determineEffectiveSpeed();
}

//may need to be updated as time goes by, we need a highest value that the engine can reach
float Engine::determineEffectiveSpeed() {
	
	return speed * (INITIAL_TEMPERATURE/temperature); //ie 100/temp
}

void Engine::setTemperature(float newTemperature)
{
	temperature = newTemperature;
}

float Engine::getTemperature()
{
	return temperature;
}

const  float Engine::INITIAL_SPEED = 50.0;

const float Engine::INITIAL_SPEED_VARIANCE = 5.0;

const float Engine::SPEED_CHANGE_VARIANCE = 2.0;

const float Engine::INITIAL_ACCELERATION = 50.0;

const float Engine::INITIAL_ACCELERATION_VARIANCE = 5.0;

const float Engine::ACCELERATION_CHANGE_VARIANCE = 2.0;

const float Engine::INITIAL_HANDLING = 0.0;

const float Engine::INITIAL_HANDLING_VARIANCE = 0.0;

const float Engine::HANDLING_CHANGE_VARIANCE = 0.0;

const float Engine::INITIAL_TEMPERATURE = 100.0;

const float Engine::MAX_ACCELERATION_VALUE = 60.0;

const float Engine::MAX_HANDLING_VALUE = 0.0;

const float Engine::MAX_SPEED_VALUE = 60.0;

const float Engine::TEMPRETURE_INCREMENT_DECREMENT = 2.5;

const float Engine::MAX_TEMP =  125.0;
