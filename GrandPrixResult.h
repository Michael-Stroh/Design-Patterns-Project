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
#include "RaceResult.h"

class GrandPrixResult : public Result
{

public:
	/**
		Constructor
	*/
	GrandPrixResult();

	/**
		Destructor
	*/
	~GrandPrixResult();

	/**
		@brief Prints the formatted results of the entire Grand Prix
	*/
	void print();

	/**
		@brief Returns a string of the formatted results for the drivers of the Grand Prix (ie. the driver's championship results)
	*/
	string getDriverPositions();

	/**
		@param[in] r: An instance of RaceResult, to be added to the total results of the race
	*/
	void addResult(Result *);

	/**
		@brief Returns a vector containing the team points for the race
	*/
	vector<pair<string, int>> getTeamPoints();

	/**
		@brief Returns a vector containing the driver points for the race
	*/
	vector<pair<string, int>> getDriverPoints();

private:
	/**
		@brief The result of the official race within a grand prix
	*/
	Result *officialRaceResult;

	/**
		@brief A collection of all the points for the drivers in the grand prix
	*/
	vector<pair<string, int>> driverPoints;

	/**
		@brief A collection of all the points for the teams in the grand prix
	*/
	vector<pair<string, int>> teamPoints;
};

#endif
