/**
   @file Result.h
   @class Result
   @authors Alex
   @version 1.0.0
   @brief The abstract class that the various Result classes (LapResult, RaceResult, GrandPrixResult, RaceSeasonResult) will inherit from.
 */

#ifndef RESULT_H
#define RESULT_H

#include "Result.h"

#include <vector>
#include <string>

using namespace std;

class Result
{

public:
	/**
			Constructor
		*/
	Result();

	/**
			Constructor
		*/
	~Result();

	/**
			
		*/
	virtual void print() = 0;

	/**
			
			@param[in]: Result: a result to be added and aggregated by the current result class. This will be a "lower level" result that will be added to other "lower level" results to form a single "higher level" result.
		*/
	void addResult(Result *);
};

#endif
