/**
   @file GrandPrixResult.h
   @class GrandPrixResult
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef GRANDPRIXRESULT_H
#define GRANDPRIXRESULT_H

#include "Result.h"

#include <map>

class GrandPrixResult: public Result {

	public:
		
		/**
			Constructor
		*/
		GrandPrixResult();

		/**
			Constructor
			@param
		*/
		GrandPrixResult( Result* );

		/**
			Constructor
			@param
			@param
		*/
		GrandPrixResult( Result*, map<string, int> );

		/**
			Destructor
		*/
		~GrandPrixResult();

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
			
		*/
		void setTeamTime( map<string, int> );

		/**
			
		*/
		void setDriverTime( map<string, int> );

	private:

		/**
			@brief 
		*/
		Result* officialRaceResult;
		
		/**
			@brief 
		*/
		map<string, int> driverPoints;
		
		/**
			@brief 
		*/
		map<string, int> teamPoints;
};

#endif
