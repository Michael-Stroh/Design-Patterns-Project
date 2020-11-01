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

