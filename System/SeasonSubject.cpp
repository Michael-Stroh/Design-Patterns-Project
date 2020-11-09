#include "SeasonSubject.h"

SeasonSubject::SeasonSubject() : Subject()
{
}

SeasonSubject::~SeasonSubject()
{
}

void SeasonSubject::notify(vector<GrandPrix *> grandPrixs)
{
	Logger::debug("SeasonSubject::notify grandprix version", "start");
	vector<RaceTeam *>::iterator it;
	for (it = this->observerList.begin(); it != this->observerList.end(); ++it)
	{
		Logger::debug("SeasonSubject::notify grandprix version", "loop");
		(*it)->informGrandPrixs(grandPrixs);
	}
	Logger::debug("SeasonSubject::notify grandprix version", "end");
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