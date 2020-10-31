/**
   @file LapResult.h
   @class LapResult
   @authors Alex
   @version 1.0.0
   @brief The ancestor of Result that will contain the lowest possible recordable result: the time taken to perform a lap.
 */

#ifndef LAPRESULT_H
#define LAPRESULT_H

#include "Result.h"
#include <string>
#include <iostream>
using namespace std;

class LapResult : public Result
{

public:
	/**
			Constructor
		*/
	LapResult();

	/**
			@param[in] d: The driver who completed the lap's name
			@param[in] t: The team who the driver is currently driving for's team
			@param[in] f: The time taken to complete a lap
		*/
	LapResult(string, string, float);

	/**
			Destructor
		*/
	~LapResult();

	/**
			
		*/
	void print();

	/**
			@return The laptime for the current lap.
		*/
	float getLapTime();

	/**
			@return The driver who completed the current lap's name.
		*/
	string getDriverName();

	/**
			@return The name of the team for which the driver who complete the current lap drives.
		*/
	string getTeamName();

private:
	/**
			@brief The time taken for a driver to complete a lap.
		*/
	float lapTime;

	/**
			@brief The name of the team for which the driver is currently driving.
		*/
	string teamName;

	/**
			@brief The name of the driver who just completed the lap.
		*/
	string driverName;
};

#endif
