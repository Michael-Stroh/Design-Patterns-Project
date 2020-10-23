/**
   @file RaceState.h
   @class RaceState
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACESTATE_H
#define RACESTATE_H

#include "Result.h"
#include "RaceTeam.h"
#include "Circuit.h"

class RaceState {

	public:
	
		/**
			Constructor
		*/
		RaceState();

		/**
			Destructor
		*/
		~RaceState();

		/**
			
			@param
			@param
			@param
			@return
		*/
		virtual Result* runRace( Result*, RaceTeam*, Circuit* ) = 0;
};

#endif
