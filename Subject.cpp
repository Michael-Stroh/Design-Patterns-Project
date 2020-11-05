#include "Subject.h"

Subject::Subject()
{

	this->observerList = vector<RaceTeam *>();
}

Subject::~Subject()
{
}

void Subject::attach(RaceTeam *r)
{

	this->observerList.push_back(r);
}

void Subject::detach(RaceTeam *r)
{
	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		if (*it == r)
		{
			this->observerList.erase(it);
		}
	}
}
