/**
   @file GrandPrixResult.h
   @class GrandPrixResult
   @authors Alex
   @version 1.0.0
   @brief The results of a Grand Prix, stored as the amount of points per driver as well as the amount of points per team.
 */

#ifndef GRANDPRIXRESULT_H
#define GRANDPRIXRESULT_H

#include "Result.h"

#include <map>
#include <string>
#include <vector>
using namespace std;

class GrandPrixResult : public Result
{

public:
	/**
		Constructor
	*/
	GrandPrixResult();

	/**
		Constructor
		@param[in] r: An instance of RaceResult (intended to be an official race result)
	*/
	GrandPrixResult(Result *);

	/**
		Destructor
	*/
	~GrandPrixResult();

	/**
		@brief Prints the formatted results of the entire Grand Prix
	*/
	void print();

	/**
		@brief Prints the formatted results for the drivers of the Grand Prix (ie. the driver's championship results)
	*/
	void printDrivers();

	/**
		@brief Prints the formatted results for the teams of the Grand Prix (ie. the constructor's championship results)
	*/
	void printTeams();

private:
	/**
		@brief The result of the official race within a grand prix
	*/
	Result *officialRaceResult;

	/**
		@brief A collection of all the points for the drivers in the grand prix
	*/
	vector<map<string, int>> driverPoints;

	/**
		@brief A collection of all the points for the teams in the grand prix
	*/
	vector<map<string, int>> teamPoints;
};

#endif
