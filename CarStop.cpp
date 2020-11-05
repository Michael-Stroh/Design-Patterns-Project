#include "CarStop.h"

CarStop::CarStop() {
}

CarStop::CarStop( string CarName ): name( CarName ) {
}

CarStop::~CarStop() {

}

string CarStop::getName() {

	return name;
}

void CarStop::setName( string CarName ) {

	name = CarName;
}

<<<<<<< HEAD
=======
Car* CarStop::getCar() {

	return car;
}


bool CarStop::setCar( Car* carChange ) {

	car = carChange;
	return true;
}

PitCrew* CarStop::getCrew() {

	return crew;
}

bool CarStop::setCrew( PitCrew* crewChange ) {

	crew = crewChange;
	return true;
}
>>>>>>> origin/master
