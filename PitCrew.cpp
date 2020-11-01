#include "PitCrew.h"

PitCrew::PitCrew(): myID(0) {}

PitCrew::~PitCrew() {
	delete myPitStop;
}


void PitCrew::registerAtPitStop(PitStop* pitstop) {
	
	myPitStop = pitstop;
	myID = myPitStop->addCrewMember(this);
	
}

void PitCrew::setID(int id) {

	myID = id;
}

int PitCrew::getID() {

	return myID;
}


