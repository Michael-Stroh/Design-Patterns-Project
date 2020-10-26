#include "Engine.h"

Engine::Engine(): CarPart() {

	// TODO - implement Engine::Engine
	throw "Not yet implemented";
}

Engine::Engine( int StartTemp ): CarPart(), temperature( StartTemp ) {

	// TODO - implement Engine::Engine
	throw "Not yet implemented";
}

Engine::~Engine() {

}

void Engine::print() {

	// TODO - implement Engine::print
	throw "Not yet implemented";
}

float Engine::determineEffectiveSpeed() {

	// TODO - implement Engine::determineEffectiveSpeed
	throw "Not yet implemented";
}

int Engine::getTemp() {

	return temperature;
}

void Engine::setTemp( int ChangeTemp ) {

	temperature = ChangeTemp;
}
