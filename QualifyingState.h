/**
   @file .h
   @class 
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef QUALIFYINGSTATE_H
#define QUALIFYINGSTATE_H

#include "RaceState.h"
#include "Result.h"
#include "Circuit.h"
#include "RaceTeam.h"

class QualifyingState: public RaceState {

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
			
			@param
			@param
			@param
			@return
		*/
		Result* runRace( Result*, RaceTeam*, Circuit* );
		
	private:
		
		/**
			@brief
		*/
		QualifyingRaceSubject* qualifyingRaceSubject;
};

#endif
