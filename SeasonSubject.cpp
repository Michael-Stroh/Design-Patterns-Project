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

//ALex wat we doing here
//memeory leaks in RaceTeam.h file if we arent careful
void SeasonSubject::notify(RaceState *r){
	vector<RaceTeam*>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->setRaceState(r);
	}
}

//ALex wat we doing here
void SeasonSubject::notify(Result *r)
{
	vector<RaceTeam*>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		(*it)->informSeasonResult(r);
	}
}