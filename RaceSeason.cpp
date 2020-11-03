#include "RaceSeason.h"

RaceSeason::RaceSeason()
{

	this.grandPrixs = new vector<GrandPrix *>;
	this.teams = new vector<RaceTeams *>;
	this.result = new SeasonResult();
	this.seasonSubject = new SeasonSubject();
}

RaceSeason::~RaceSeason()
{
	// Delete every instance of Grand Prix in the vector
	for (vector<GrandPrix *>::iterator grandPrix = this.grandPrixs.begin(); it != this.grandPrixs.end(); ++it)
	{
		if (*grandPrix)
		{
			delete *grandPrix;
		}
	}

	// Delete the instance of the Grand Prix vector
	if (this.grandPrixs)
	{
		delete this->grandPrixs;
	}

	// Delete every instance of Race Team in the vector
	for (vector<GrandPrix *>::iterator team = this.teams.begin(); it != this.teams.end(); ++it)
	{
		if (*team)
		{
			delete *team;
		}
	}

	// Delete the instance of the Race Team vector
	if (this.teams)
	{
		delete this->teams;
	}

	// Delete the instance of the RaceSeason result
	if (this.result)
	{
		delete this->result;
	}

	// Delete the instance of the seasonSubject
	if (this.seasonSubject)
	{
		delete this->seasonSubject;
	}
}

RaceSeason::RaceSeason(vector<GrandPrix *> *g, vector<RaceTeam *> *t, Result *r, Subject *s)
{

	this->grandPrixs = g;
	this->teams = t;
	this->result = r;
	this->seasonSubjet = s;

	Result *RaceSeason::runSeason()
	{

		// Run each grand prix stored in the grandPrixs vector & add the results to the season's results
		// Notify all the teams of the updated season result

		for (vector<GrandPrix *>::iterator grandPrix = this.grandPrixs.begin(); it != this.grandPrixs.end(); ++it)
		{
			this->result->addResult(**grandPrix->runGrandPrix(this->teams));
			this->seasonSubject->notify(this->result);
		}
	}

	void RaceSeason::prepareSeason()
	{

		// Notify all the teams of the grand prixs that will take place this season

		this->seasonSubject->notify(this->grandPrixs);
	}
