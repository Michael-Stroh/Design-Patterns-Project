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
		it->informGrandPrixs(grandPrixs);
	}
}