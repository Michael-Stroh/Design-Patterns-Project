#include "Engine.h"

//Should never be used
Engine::Engine() {
	
}

Engine::Engine(float s, float h, float a, string b) : CarPart(s,h,a, "Engine", b)
{

}

Engine::~Engine()
{
	
}

float Engine::getSpeed()
{
	return determineEffectiveSpeed;
}

float Engine::determineEffectiveSpeed() {
	
	return speed * (temperature/100);
}

void Engine::setTemperature(float newTemperature)
{
	temperature = newTemperature;
}

float Engine::getTemperature()
{
	return temperature;
}