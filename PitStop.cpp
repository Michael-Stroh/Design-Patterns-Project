#include "PitStop.h"
#include "PitCrew.h"

PitStop::PitStop() : crewMemberID(0) {
}

PitStop::~PitStop() {
	pitcrew.clear();
}

int PitStop::addCrewMember(PitCrew * crewMember) {
	PitCrew * newMember = crewMember;
	newMember->setID(crewMemberID++);
	pitcrew.push_back(newMember);
	return newMember->getID();
	
}

TyreStrategy * PitStop::changeTyre(TyreStrategy * tyreStrategy)
{
	TyreStrategy * temp = tyreStrategy;
	
	vector<Tyre *> tyres = tyreStrategy->getTyres();
	tyres.pop_back();
	
	
	
	temp->setTyres(tyres);
	
	return temp;
}

