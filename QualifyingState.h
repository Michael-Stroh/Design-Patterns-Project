/**
   @file .h
   @class 
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef QUALIFYINGSTATE_H
#define QUALIFYINGSTATE_H

#include "QualifyingRaceSubject.h"
#include "RaceState.h"
#include "RaceTeam.h"
#include "Circuit.h"
#include "Result.h"

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
