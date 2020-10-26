/**
   @file RaceResult.h
   @class RaceResult
   @authors Alex
   @version 1.0.0
   @brief The ancestor of Result that will contain the results of a single race.
 */

#ifndef RACERESULT_H
#define RACERESULT_H

#include "Result.h"
#include <string>
#include <map>
using namespace std;

class RaceResult : public Result
{

public:
	/**
			Constructor
		*/
	RaceResult();

	/**
			Copy Constructor
			@param[in] r: An instance of Result
		*/
	RaceResult(Result *);

	/**
			Destructor
		*/
	~RaceResult();

	/**
			
			@param[in] r: An instance of LapResult, to be added to the total results of the race
		*/
	bool addLapTime(Result *);

	/**
			@brief Prints the formatted results of the race
		*/
	void print();

	/**
			@brief prints the results of the Driver's of the race (for the driver's championship)
		*/
	void printDrivers();

	/**
			@brief prints the results of the Teams's of the race (for the teams's championship)
			
		*/
	void printTeams();

private:
	/**
			@brief A collection of all the lapresults for the current race
		*/
	Result *lapResult;

	/**
			@brief A collection of all the lapresults for the teams for the current race
		*/
	map<string, int> totalTeamsLaptime;

	/**
			@brief A collection of all the lapresults for the drivers for the current race
		*/
	map<string, int> totalDriversLaptime;
};

#endif
