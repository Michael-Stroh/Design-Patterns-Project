/**
   @file RaceSeasonResult.h
   @class RaceSeasonResult
   @authors Alex
   @version 1.0.0
   @brief 
 */

#ifndef RACESEASONRESULT_H
#define RACESEASONRESULT_H

#include "Result.h"

#include <map>

class RaceSeasonResult : public Result
{

public:
	/**
			Constructor
		*/
	RaceSeasonResult();

	/**
			Constructor
			@param
			@param
			@param
		*/
	RaceSeasonResult(Result *, map<string, int>, map<string, int>);

	/**
			Constructor
			@param
		*/
	RaceSeasonResult(Result *);

	/**
			Destructor
		*/
	~RaceSeasonResult();

	/**
			
			@param
		*/
	void addResult(Result *r);

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
	void setTeamTime(map<string, int>);

	/**
			
			@param
		*/
	void setDriverTime(map<string, int>);

private:
	/**
			@brief
		*/
	Result *grandPrixResults;

	/**
			@brief
		*/
	map<string, int> totalDriverPoints;

	/**
			@brief
		*/
	map<string, int> totalTeamPoints;
};

#endif
