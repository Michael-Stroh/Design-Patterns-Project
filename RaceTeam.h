/**
   @file Racing_Team.h
   @class Racing_Team
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACING_TEAM_H
#define RACING_TEAM_H

#include "Result.h"
//#include "GrandPrix.h"
#include "Driver.h"
#include "Car.h"
#include "CarBuilder.h"
#include "Strategies.h"
#include "LapResult.h"
using namespace std;

class GrandPrix;

class RaceTeam {

	public:
		
		/**
			Constructor
		*/
		RaceTeam();
		
		/**
			Destructor
		*/
		~RaceTeam();
		
		/**
			
			@param
			@return
		*/
		LapResult* performLap( int );

		/**
			
			@param
		*/
		void updateSeasonResult( int );

		/**
			
			@param
		*/
		void updateQualifyingRaceResult( int );

		/**
			
			@param
			@return
		*/
		bool updateOfficialRaceResult( Result* );

		/**
			
			@param
		*/
		void informGrandPrix( GrandPrix * );
		
	private:
	
		/**
			@brief
		*/
		Driver* driver;
		
		/**
			@brief
		*/
		Car* car;
		
		/**
			@brief
		*/
		CarBuilder* builder;
		
		/**
			@brief
		*/
		Strategies* Strategy;
};

#endif
