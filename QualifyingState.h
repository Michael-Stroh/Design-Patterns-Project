/**
   @file .h
   @class 
   @authors Alex
   @version 1.0.0
   @brief The Qualfying state for the Race class.
   @details Responsible for performing the necessary steps to complete a qualfiying race.
 */

#ifndef QUALIFYINGSTATE_H
#define QUALIFYINGSTATE_H

#include "RaceState.h"
#include "Result.h"
#include "Circuit.h"
#include "RaceTeam.h"

class QualifyingState : public RaceState
{

public:
	/**
			Constructor
		*/
	QualifyingState();

	/**
			Destructor
		*/
	~QualifyingState();

	/**
			
			@param Result: The results of the previous race (Can be NULL in this case as it will not be used in the qualifying race).
			@param RaceTeam: The teams that will participate in the qualfying race.
			@param Circuit: The circuit on which the qualfying race will take place.
			@return The result of the qualfying race.
		*/
	Result *runRace(Result *, RaceTeam *, Circuit *);

private:
	/**
			@brief The subject that will allow all teams to be informed of any necessary information before or during the qualfying race.
		*/
	QualifyingRaceSubject *qualifyingRaceSubject;
};

#endif
