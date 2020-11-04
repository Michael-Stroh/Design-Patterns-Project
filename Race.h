/**
   @file Race.h
   @class Race
   @authors Alex
   @version 1.0.0
   @brief The races that will take place during a Grand Prix. Responsible for performing the steps followed for each different race type (Practice, Qualifying & Official)
 */

#ifndef RACE_H
#define RACE_H

#include "RaceSubject.h"
#include "Circuit.h"
#include "RaceTeam.h"
#include "PracticeState.h"
#include "QualifyingState.h"
#include "OfficialState.h"
#include <vector>

class Race
{

public:
	/**
			Constructor
		*/
	Race();

	/**
			Destructor
			@details: Free's the following memory
			- The private state variable
			- The private raceSubject variable
			- The private state instances

		*/
	virtual ~Race();

	/**
			
			@param[in] result: The results of a previous race, taken into account if the next race requires it.
			@param[in] teams: All of the teams participating in the current race.
			@param[in] circuit: The circuit on which the current race will take place.
			@return
		*/
	Result *runRace(Result *, vector<RaceTeam *> *, Circuit *);

	/**
			
			@param[in] _state: A string describing the state to which the race must be set. Either "Practice", "Qualifying", or "Official"
		*/
	void setState( string  );

	/**
			
			@param[in]: r: The race subject that will be used to inform any racing teams of updates before or during the race.
		*/
	void setRaceSubject(RaceSubject *);

private:
	/**
			@brief The current state that the race is in. Either "Practice", "Qualifying" or "Official"
		*/
	RaceState* state;

	/**
			@brief The Race Subject used to inform any racing teams of updates before or during the race.
		*/
	RaceSubject *raceSubject;

	/**
			@brief The results of the race;
		*/
	Result *result;

	/**
		@brief A pointer to an instance of PracticeState, used to update the race's state
	*/
	PracticeState *practiceState;

	/**
		@brief A pointer to an instance of QualfyingState, used to update the race's state
	*/
	QualifyingState *qualifyingState;

	/**
		@brief A pointer to an instance of OfficialState, used to update the race's state
	*/
	OfficialState *officialState;
};

#endif
