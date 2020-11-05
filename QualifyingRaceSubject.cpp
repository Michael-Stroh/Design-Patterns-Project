#include "QualifyingRaceSubject.h"

QualifyingRaceSubject::QualifyingRaceSubject() : Subject()
{
}

QualifyingRaceSubject::~QualifyingRaceSubject()
{
}

void QualifyingRaceSubject::notify(Result *r)
{
	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->updateQualifyingRaceResult(r);
	}
}
