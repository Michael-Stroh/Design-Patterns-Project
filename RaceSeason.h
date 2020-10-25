/**
   @file Race_Season.h
   @class Race_Season
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACE_SEASON_H
#define RACE_SEASON_H

#include "GrandPrix.h"
#include "RacingTeam.h"
#include "Result.h"
#include "Subject.h"

class Race_Season {

	public:
	
		/**
			Constructor
		*/
		Race_Season();

		/**
			Constructor
			@param
			@param
			@param
			@param
		*/
		Race_Season( GrandPrix*, RacingTeam*, Result*, Subject* );

		/**
			Destructor
		*/
		~Race_Season();
	
		/**
			
			@return
		*/
		Result* runSeason();

		/**
			
		*/
		void prepareSeason();
		
	private:
	
		/**
			@brief 
		*/
		GrandPrix* grandPrixs;
		
		/**
			@brief 
		*/
		RacingTeam* teams;
		
		/**
			@brief 
		*/
		Result* result;
		
		/**
			@brief 
		*/
		Subject* seasonSubject;
	
};

#endif
