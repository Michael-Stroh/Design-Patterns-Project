#include "PitStop.h"
#include "PitCrew.h"

PitStop::PitStop() : crewMemberID(0) {
}

PitStop::~PitStop() {
	pitcrew.clear();
}

int PitStop::addCrewMember(PitCrew* crewMember) {
	crewMember->setID(crewMemberID++);
	pitcrew.push_back(crewMember);
	return crewMember->getID();

}

TyreStrategy* PitStop::changeTyre(TyreStrategy* tyreStrategy)
{


	vector<Tyre*> tyres = tyreStrategy->getTyres();
	tyres.pop_back();

	vector<Tyre*>::iterator i = tyres.end();
	i--;
	//cout<<(*i)->getTyreType()<<endl;

	TyreStrategy* temp = new TyreStrategy();

	temp->setTyres(tyres);

	return temp;
}

PitCrew* PitStop::getCrewMember(int id)
{
	vector<PitCrew*>::iterator i = pitcrew.begin();
	int j = 0;
	for (; i != pitcrew.end(); i++)
	{
		if (j == id)
			return (*i);
	}
	return NULL;
}

void PitStop::setPitStop(PitStop* pitstop)
{
	if (pitstop != NULL) {
		vector<PitCrew*>::iterator it = pitstop->getPitCrew().begin();
		for (; it != pitstop->getPitCrew().end(); it++)
			pitcrew.push_back(*it);
	}
}

vector<PitCrew*> PitStop::getPitCrew()
{
	return pitcrew;
}

