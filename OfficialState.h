/**
   @file OfficialState.h
   @class OfficialState
   @authors Alex
   @version 1.0.0
   @brief The Official state for the Race class.
   @details Responsible for performing the necessary steps to complete an official race.
   
 */

#ifndef OFFICIALSTATE_H
#define OFFICIALSTATE_H

#include "RaceSubject.h"
#include "RaceState.h"
#include "RaceTeam.h"
#include "Result.h"
#include "RaceResult.h"
#include "LapResult.h"

class OfficialState : public RaceState
{

public:
	/**
			Constructor
		*/
	OfficialState();

	/**
			Constructor
		*/
	~OfficialState();

	/**
			
			@param Result: The results of the previous race (CANNOT be NULL in this case, will be used to complete the official race).
			@param RaceTeam: The teams that will participate in the official race.
			@param Circuit: The circuit on which the official race will take place.
			@return The result of the official race.
		*/
	Result *runRace( Result*, vector< RaceTeam* >, RaceTrack* );

private:
	/**
		@brief The subject that will allow all teams to be informed of any necessary information before or during the official race.
		*/
	RaceSubject *raceSubject;
};

#endif
