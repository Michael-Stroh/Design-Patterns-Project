/**
   @file LogisiticsStrategy.h
   @class LogisiticsStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef LOGISITICSSTRATEGY_H
#define LOGISITICSSTRATEGY_H

#include "Logistics.h"
#include "RaceTrack.h"

#include <vector> 

class LogisticsStrategy {

	public:
		
		/**
			Constructor
		*/
		LogisticsStrategy(RaceTrack* rt);

		/**
			Destructor
		*/
		~LogisticsStrategy();
		
		/**
			signal method to transport car to factory
		*/
		void endOfRace();
		
		/**
			signal method to transport car from factory to race
		*/
		void startOfRace();
		
		/**
			signal method to transport car from factory to race
			@param month is the current month of the year
		*/
		void newMonthNewLog(int month);
		
		/**
			@param the full date 
			@brief takes the value  input and only returns the month as an int
		*/
		int getMonth(string date);
	
	private:

		/**
			@brief 
		*/
		vector<Logistics*> logisitics;
		
		/**
			@brief 
		*/
		RaceTrack* rt;
};

#endif
