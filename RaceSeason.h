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
#include "RaceTeam.h"
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
	Race_Season(GrandPrix *, RaceTeam *, Result *, Subject *);

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
			@brief Performs all necessary actions that occur before the Race Season begins.
		*/
	void prepareSeason();

private:
	/**
			@brief All of the grand prixs that will take place during the racing season.
		*/
	GrandPrix *grandPrixs;

	/**
			@brief All of the racing teams that will participate in the racing season.
		*/
	RacingTeam *teams;

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
