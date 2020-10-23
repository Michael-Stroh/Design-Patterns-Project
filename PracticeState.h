/**
   @file PracticeState.h
   @class PracticeState
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef PRACTICESTATE_H
#define PRACTICESTATE_H

#include "RaceState.h"
#include "RaceTeam.h"
#include "Circuit.h"
#include "Result.h"

class PracticeState: public RaceState {

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
			
			@param
			@param
			@param
			@return
		*/
		Result* runRace( Result*, RaceTeam*, Circuit* );
};

#endif
