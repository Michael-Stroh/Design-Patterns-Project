/**
   @file OfficialState.h
   @class OfficialState
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef OFFICIALSTATE_H
#define OFFICIALSTATE_H

#include "OfficialRaceSubject.h"
#include "RaceState.h"
#include "RaceTeam.h"
#include "Result.h"
#include "Circuit.h"

class OfficialState: public RaceState {

	public:

		/**
			Constructor
		*/
		OfficialState();

		/**
			Constructor
		*/
		void ~OfficialState();

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
		OfficialRaceSubject* officialRaceSubject;
};

#endif
