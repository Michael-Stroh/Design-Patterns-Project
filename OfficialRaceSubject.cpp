#include "OfficialRaceSubject.h"

OfficialRaceSubject::OfficialRaceSubject() : Subject()
{
}

OfficialRaceSubject::~OfficialRaceSubject()
{
}

void OfficialRaceSubject::notify(Result *r)
{
	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->updateOfficialRaceResult(r);
	}
}
