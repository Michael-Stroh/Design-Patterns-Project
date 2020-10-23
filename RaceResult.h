/**
   @file RaceResult.h
   @class RaceResult
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACERESULT_H
#define RACERESULT_H

#include "Result.h"

#include <map>

class RaceResult: public Result {



	public:
	
		/**
			Constructor
		*/
		RaceResult();

		/**
			Constructor
			@param
		*/
		RaceResult( Result* );

		/**
			Constructor
			@param
			@param
		*/
		RaceResult( Result*, map<string, int> );

		/**
			Constructor
		*/
		~RaceResult();

		/**
			
			@param
		*/
		bool addLapTime( Result* );

		/**
			
		*/
		void print();

		/**
			
		*/
		void printDrivers();

		/**
			
		*/
		void printTeams();

		/**
			
			@param
		*/
		void setTeamTime( map<string, int> );

		/**
			
			@param
		*/
		void setDriverTime( map<string, int> );
		
		
	private:
		
		/**
			@brief
		*/
		Result* lapResult;
		
		/**
			@brief
		*/
		map<string, int> totalTeamsLaptime;
		
		/**
			@brief
		*/
		map<string, int> totalDriversLaptime;
};

#endif
