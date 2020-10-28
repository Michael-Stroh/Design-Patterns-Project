/**
   @file RaceSeason.h
   @class RaceSeason
   @authors Alex
   @version 1.0.0
   @brief Responsible for running all of the Grand Prixs in a season and ensuring all participating teams are aware of the season before it starts as well keeping them updated on its progress while it takes place.
 */

#ifndef RACE SEASON_H
#define RACE SEASON_H

#include "GrandPrix.h"
#include "RaceTeam.h"
#include "GrandPrixResult.h"
#include "Subject.h"
#include <vector>
using namespace std;

class RaceSeason
{

public:
	/**
			Constructor
			@details Will instantiate all of the member variables with new instances of their respective types.
		*/
	RaceSeason();

	/**
			Constructor
			@param[in] g: All the Grand_Prix that will take place this race season.
			@param[in] t: All the Racing_Team that will be participating in the race season.
			@param[in] r: An instantiated (but not yet containing any information) RaceSeasonResult that will be added to as the RaceSeason unfolds.
			@param[in] s: The SeasonSubject, used to notify RaceTeams of the particulars of the RaceSeason before or during the season.
		*/
	RaceSeason(vecotr<GrandPrix *>, RaceTeam *, Result *, Subject *);

	/**
			Destructor
			@details Will delete the following pointers:
			- Every grand prix in the grandPrixs vector
			- The grandPrix vector
			- Every race team in the raceTeam vector
			- The race season's result
			- The race season subject
		*/
	~RaceSeason();

	/**
			@brief Runs the entire race season
			@details Will iterate through the collection of GrandPrixs, running each individually calling the GrandPrix.runGrandPrix() method. This will return a result for each GrandPrix, which is added to the SeasonResult (thus aggregating each GrandPrixs result into a final RaceSeasonResult).
			@return A RaceSeasonResult object, that can be used to access the results of the entire RaceSeason.
			@todo Implement RaceSeasonResult::addResult
			@todo Implement seasonSubject::notify(RaceSeasonResult)
		*/
	Result *runSeason();

	/**
			@brief Performs all necessary actions that occur before the Race Season begins.
			@todo Implement seasonSubject::notify(vector<GrandPrix*>*)

		*/
	void prepareSeason();

private:
	/**
			@brief All of the grand prixs that will take place during the racing season.
		*/
	vector<GrandPrix *> grandPrixs;

	/**
			@brief All of the racing teams that will participate in the racing season.
		*/
	vector<RaceTeam *> teams;

	/**
			@brief The overall Season Result, this will be updated everytime a grand prix completes.
		*/
	Result *result;

	/**
			@brief The Season Subject, to which each racing team attaches so that they can be informed of any pertinent information regarding the Race Season.
		*/
	Subject *seasonSubject;
};

#endif