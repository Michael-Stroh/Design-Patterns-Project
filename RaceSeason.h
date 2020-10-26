/**
   @file Race_Season.h
   @class Race_Season
   @authors Alex
   @version 1.0.0
   @brief Responsible for running all of the Grand Prixs in a season and ensuring all participating teams are aware of the season before it starts as well keeping them updated on its progress while it takes place.
 */

#ifndef RACE SEASON_H
#define RACE SEASON_H

#include "GrandPrix.h"
#include "RacingTeam.h"
#include "Result.h"
#include "Subject.h"

class Race_Season
{

public:
	/**
			Constructor
		*/
	Race_Season();

	/**
			Constructor
			@param[in] g: All the Grand_Prix that will take place this race season.
			@param[in] t: All the Racing_Team that will be participating in the race season.
			@param[in] r: An instantiated (but not yet containing any information) RaceSeasonResult that will be added to as the RaceSeason unfolds.
			@param[in] s: The SeasonSubject, used to notify RaceTeams of the particulars of the Race_Season before or during the season.
		*/
	Race_Season(GrandPrix *, RacingTeam *, Result *, Subject *);

	/**
			Destructor
		*/
	~Race_Season();

	/**
			@brief Runs the entire race season
			@details Will iterate through the collection of GrandPrixs, running each individually calling the GrandPrix.runGrandPrix() method. This will return a result for each GrandPrix, which is added to the SeasonResult (thus aggregating each GrandPrixs result into a final RaceSeasonResult).
			@return A RaceSeasonResult object, that can be used to access the results of the entire RaceSeason.
		*/
	Result *runSeason();

	/**
			
		*/
	void prepareSeason();

private:
	/**
			@brief 
		*/
	GrandPrix *grandPrixs;

	/**
			@brief 
		*/
	RacingTeam *teams;

	/**
			@brief 
		*/
	Result *result;

	/**
			@brief 
		*/
	Subject *seasonSubject;
};

#endif
