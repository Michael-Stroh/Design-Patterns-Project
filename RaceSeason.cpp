#include "RaceSeason.h"

RaceSeason::RaceSeason()
{

	this->grandPrixs = vector<GrandPrix *>();
	this->teams = vector<RaceTeam *>();
	this->result = new RaceSeasonResult();
	this->seasonSubject = new SeasonSubject();
}

RaceSeason::RaceSeason(vector<GrandPrix *> g, vector<RaceTeam *> t)
{
	this->grandPrixs = g;
	this->teams = t;
	this->result = new RaceSeasonResult();
	this->seasonSubject = new SeasonSubject();
}

RaceSeason::~RaceSeason()
{
	// Delete every instance of Grand Prix in the vector & remove the item from the vector
	for (vector<GrandPrix *>::iterator grandPrix = this->grandPrixs.begin(); grandPrix != this->grandPrixs.end(); ++grandPrix)
	{
		if (*grandPrix)
		{
			delete *grandPrix;
		}
		grandPrixs.erase(grandPrix);
	}

	// Delete every instance of Race Team in the vector & remove the item from the vector
	for (vector<RaceTeam *>::iterator team = this->teams.begin(); team != this->teams.end(); ++team)
	{
		if (*team)
		{
			delete *team;
		}
		teams.erase(team);
	}

	// Delete the instance of the RaceSeason result
	if (this->result)
	{
		delete this->result;
	}
	this->result = nullptr;

	// Delete the instance of the seasonSubject
	if (this->seasonSubject)
	{
		delete this->seasonSubject;
	}
	this->seasonSubject = nullptr;
}

Result *RaceSeason::runSeason()
{

	// Run each grand prix stored in the grandPrixs vector & add the results to the season's results
	// Notify all the teams of the updated season result

	for (vector<GrandPrix *>::iterator grandPrix = this->grandPrixs.begin(); grandPrix != this->grandPrixs.end(); ++grandPrix)
	{
		this->result->addResult((*grandPrix)->runGrandPrix(this->teams));
		this->seasonSubject->notify(this->result);
	}
	return this->result;
}

void RaceSeason::prepareSeason()
{

	// Notify all the teams of the grand prixs that will take place this season

	this->seasonSubject->notify(this->grandPrixs);
}
