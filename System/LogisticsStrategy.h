/**
   @file LogisticsStrategy.h
   @class LogisticsStrategy
   @authors Brent
   @version 1.0.0
   @brief Creates the RaceSchedule and determines when shipping needs to occur.
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
	void endOfRace(string name);

	/**
		signal method to transport car to factory
	*/
	int getMonth(string date);

	/**
			signal method to transport car to factory
		*/
	RaceTrack* getRace(string name);


private:

	/**
		@brief holds the logisitics strategy for the whole season
	*/
	vector<Logistics*> logisitics;


	/**
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
	int tracker;
};

#endif
