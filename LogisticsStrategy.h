/**
   @file LogisiticsStrategy.h
   @class LogisiticsStrategy
   @authors Michael
   @authors Brent
   @version 1.0.0
   @brief 
 */


#ifndef LOGISITICSSTRATEGY_H
#define LOGISITICSSTRATEGY_H

#include "Logistics.h"
#include "RaceTrack.h"

#include <vector> 
#include <string>

class LogisticsStrategy {

	public:
		
		/**
			Constructor
		*/
		LogisticsStrategy(RaceTrack* rt);
		LogisticsStrategy(vector<RaceTrack*>);

		/**
			Destructor
		*/
		~LogisticsStrategy();
		
		Logistics* getLogistics(string name);
		
		void setDates(vector<RaceTrack*>);
		
		/**
			signal method to transport car to factory
		*/
		void endOfRace();
		void endOfRace(string name);
		
		/**
			signal method to transport car from factory to race
			signal method to transport car to factory
		*/
		void startOfRace();
		int getMonth(string date);
		
		/**
			signal method to transport car from factory to race
			@param month is the current month of the year
	/**
			signal method to transport car to factory
		*/
		void newMonthNewLog(int month);
		RaceTrack* getRace(string name);
		
		
		/**
			@param the full date 
			@brief takes the value  input and only returns the month as an int
		*/
		int getMonth(string date);
	
	private:

		/**
			@brief 
			@brief holds the logisitics strategy for the whole season
		*/
		vector<Logistics*> logisitics;
		
		
		/**
			@brief 
			@brief the variable that holds all the dates for when logisitics needs to happen
		*/
		vector<string> dates;
		
		/**
		*/
		vector<string> names; 
		
		/**
			@brief the variable that holds all the dates for when logisitics needs to happen
		*/
		vector<RaceTrack*> races;
		
		/**
		
		*/
		RaceTrack* rt;
		int tracker;
};

#endif
