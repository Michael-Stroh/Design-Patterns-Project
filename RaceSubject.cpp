#include "RaceSubject.h"

RaceSubject::RaceSubject() : Subject()
{
}

RaceSubject::~RaceSubject()
{
}

void RaceSubject::notify(RaceState *r)
{
	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->setRaceState(r);
	}
}
