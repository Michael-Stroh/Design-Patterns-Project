/**
   @file RaceState.h
   @class RaceState
   @authors Alex
   @version 1.0.0
   @brief The abstract class from which the various Race Subjects (Practice, Qualifying & Official) will inherit.
 */

#ifndef RACESTATE_H
#define RACESTATE_H

#include "Result.h"
#include "RaceTeam.h"
#include "Circuit.h"
#include <vector>
using namespace std;

class RaceTeam;
//class RaceState;		//why

class RaceState {

	public:
		/**
				Constructor
			*/
		RaceState();

		/**
				Destructor
			*/
		virtual ~RaceState();

		/**

				@param Result: The results of the previous race (will be used within the function if necessary).
				@param RaceTeam: The teams that will participate in the race.
				@param Circuit: The circuit on which the race will take place.
				@return The result for the race.
			*/
		virtual Result* runRace( Result *, vector<RaceTeam *>, RaceTrack* ) = 0;
};

#endif
