/**
   @file PracticeState.h
   @class PracticeState
   @authors Alex
   @version 1.0.0
   @brief The Practice State for the Race class.
   @details Responsible for performing the necessary steps to complete a practice race.
 */

#ifndef PRACTICESTATE_H
#define PRACTICESTATE_H

#include "RaceState.h"
#include "RaceTeam.h"
#include "Circuit.h"
#include "Result.h"

class PracticeState : public RaceState
{

public:
	/**
			Constructor
		*/
	PracticeState();

	/**
			Destructor
		*/
	~PracticeState();

	/**
			
			@param Result: The results of the previous race (Can be NULL in this case as it will not be used in the practice race).
			@param RaceTeam: The teams that will participate in the practice race.
			@param Circuit: The circuit on which the practice race will take place.
			@return The result of the practice race.
		*/
	Result *runRace(Result *, RaceTeam *, Circuit *);
};

#endif
