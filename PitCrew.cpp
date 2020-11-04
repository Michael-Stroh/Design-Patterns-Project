#include "PitCrew.h"

PitCrew::PitCrew(): status( false ) {

	// TODO - implement PitCrew::PitCrew
	throw "Not yet implemented";
}

PitCrew::~PitCrew() {

}


void PitCrew::registerWork(PitStop* p) {

	// TODO - implement PitCrew::registerWork
	throw "Not yet implemented";
}

void PitCrew::setCar(int i) {

	// TODO - implement PitCrew::setCar
	throw "Not yet implemented";
}

void PitCrew::getStatus( bool changeStatus ) {

	status = changeStatus;
}

bool PitCrew::getStatus() {

	return status;
}
