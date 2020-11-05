#include "SeasonSubject.h"

SeasonSubject::SeasonSubject() : Subject()
{
}

SeasonSubject::~SeasonSubject()
{
}

void SeasonSubject::notify(vector<GrandPrix *> grandPrixs)
{

	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->informGrandPrixs(grandPrixs);
	}
}

void SeasonSubject::notify(RaceState *r){
	throw "Not yet implemented";
}

void SeasonSubject::notify(Result *r)
{
	throw "Not yet implemented";
}