/**
   @file Race.h
   @class Race
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACE_H
#define RACE_H

#include "RaceState.h"
#include "RaceSubject.h"
#include "Circuit.h"
#include "RaceTeam.h"
#include "Result.h"

class Race {

	public:
	
		/**
			Constructor
		*/
		Race();

		/**
			Constructor
			@param
			@param
		*/
		Race(RaceState* s, RaceSubject* r);

		/**
			Destructor
		*/
		~Race();

		/**
			
			@param
			@param
			@param
			@return
		*/
		Result* runRace(Result*, RaceTeam*, Circuit* );

		/**
			
			@param
		*/
		void setState( string );

		/**
			
			@param
		*/
		void setRaceSubject( RaceSubject* );
		
	private:
		
		/**
			@brief
		*/
		RaceState* state;
		
		/**
			@brief
		*/
		RaceSubject* raceSubject;
};

#endif
