#include "RaceSubject.h"

RaceSubject::RaceSubject() : Subject()
{
}

RaceSubject::~RaceSubject()
{
}

void RaceSubject::notify(RaceState *r)
{
	Logger::debug("RaceSubject::notfy start", "");
	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->setRaceState(r);
	}
	Logger::debug("RaceSubject::notfy finished", "");
}
