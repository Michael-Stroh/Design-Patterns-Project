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
	
	return speed * (100.0/temperature);
}

void Engine::setTemperature(float newTemperature)
{
	temperature = newTemperature;
}

float Engine::getTemperature()
{
	return temperature;
}

const  float Engine::INITIAL_SPEED = 55.0;

const float Engine::INITIAL_SPEED_VARIANCE = 5.0;

const float Engine::SPEED_CHANGE_VARIANCE = 2.0;

const float Engine::INITIAL_ACCELERATION = 55.0;

const float Engine::INITIAL_ACCELERATION_VARIANCE = 5.0;

const float Engine::ACCELERATION_CHANGE_VARIANCE = 2.0;

const float Engine::INITIAL_HANDLING = 0.0;

const float Engine::INITIAL_HANDLING_VARIANCE = 0.0;

const float Engine::HANDLING_CHANGE_VARIANCE = 0.0;

const  float Engine::INITIAL_TEMPERATURE = 100.0;
