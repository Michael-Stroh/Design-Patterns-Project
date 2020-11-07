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
	this->grandPrixIterator = this->grandPrixs.begin();
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



void RaceSeason::runNextGrandPrix(){
	Logger::debug("Race Season initiating Grand Prix", "");
	this->result->addResult((*this->grandPrixIterator)->runGrandPrix(this->teams));
	++this->grandPrixIterator;
}

bool RaceSeason::hasNextGrandPrix(){
	return (this->grandPrixIterator != this->grandPrixs.end());
}

void RaceSeason::prepareSeason()
{

	// Notify all the teams of the grand prixs that will take place this season
	this->seasonSubject->notify(this->grandPrixs);

	// Provide all teams with the result of the season
	this->seasonSubject->notify(this->result);
}

Result* RaceSeason::getResult(){
	return this->result;
}
