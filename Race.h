/**
   @file Race.h
   @class Race
   @authors Alex
   @version 1.0.0
   @brief The races that will take place during a Grand Prix. Responsible for performing the steps followed for each different race type (Practice, Qualifying & Official)
 */

#ifndef RACE_H
#define RACE_H

#include "RaceState.h"
#include "RaceSubject.h"
#include "Circuit.h"
#include "RaceTeam.h"
#include "Result.h"

class Race
{

public:
	/**
			Constructor
		*/
	Race();

	/**
			Constructor
			@param s: The initial race state (either practice, qualifying or official). 
			@param r: The Race Subject, allowing for racing teams to be notified of any pertinent details regarding a race either before or during the race.
		*/
	Race(RaceState *, RaceSubject *);

	/**
			Destructor
		*/
	~Race();

	/**
			
			@param[in] result: The results of a previous race, taken into account if the next race requires it.
			@param[in] teams: All of the teams participating in the current race.
			@param[in] circuit: The circuit on which the current race will take place.
			@return
		*/
	Result *runRace(Result *, RaceTeam *, Circuit *);

	/**
			
			@param[in] s: A string describing the state to which the race must be set. Either "Practice", "Qualifying", or "Official"
		*/
	void setState(RaceState *);

	/**
			
			@param[in]: r: The race subject that will be used to inform any racing teams of updates before or during the race.
		*/
	void setRaceSubject(RaceSubject *);

private:
	/**
			@brief The current state that the race is in. Either "Practice", "Qualifying" or "Official"
		*/
	RaceState *state;

	/**
			@brief The Race Subject used to inform any racing teams of updates before or during the race.
		*/
	RaceSubject *raceSubject;
};

#endif
