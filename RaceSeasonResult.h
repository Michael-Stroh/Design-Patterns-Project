/**
   @file RaceSeasonResult.h
   @class RaceSeasonResult
   @authors Alex
   @version 1.0.0
   @brief The class that will store the results of an entire race season
 */

#ifndef RACESEASONRESULT_H
#define RACESEASONRESULT_H

#include "Result.h"
#include "GrandPrixResult.h"
#include <iostream>
#include <vector>
using namespace std;

class RaceSeasonResult : public Result
{

public:
	/**
			Constructor
		*/
	RaceSeasonResult();

	/**
			Destructor
		*/
	~RaceSeasonResult();

	/**
			@param: An instance of GrandPrixResult
		*/
	void addResult(Result *);

	/**
		@brief: Prints out the results of the Drivers Championship and the Constructors Championship
	*/
	void print();

	/**
		@brief: Prints out the results of the Drivers Championship
		*/
	void printDrivers();

	/**
	    @brief: Prints out the results of the Constructors Championship
		*/
	void printTeams();

private:
	/**
			@brief: Stores all of the individual grand prix results
		*/
	vector<Result *> grandPrixResults;

	/**
			@brief: Stores each of the drivers total points
		*/
	vector<pair<string, int>> totalDriverPoints;

	/**
			@brief: Stores each of the teams total points
		*/
	vector<pair<string, int>> totalTeamPoints;
};

#endif
