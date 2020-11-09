#include "PitCrew.h"

PitCrew::PitCrew() : myID(0) {
	myPitStop = new PitStop;
}

PitCrew::~PitCrew() {
	delete myPitStop;
}


void PitCrew::registerAtPitStop(PitStop* pitstop) {
	myID = pitstop->addCrewMember(this);
	//myPitStop->setPitStop(pitstop);


}

void PitCrew::setID(int id) {

	myID = id;
}

int PitCrew::getID() {

	return myID;
}

PitStop* PitCrew::getPitStop()
{
	return myPitStop;
}



