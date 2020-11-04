\/**
   @file GrandPrix.h
   @class GrandPrix
   @authors Alex
   @version 1.0.0
   @brief Responsible for running the practice, qualifying & official races that take place on a specific circuit during a Grand Prix. 
 */

#ifndef GRAND PRIX_H
#define GRAND PRIX_H

#include "RaceTeam.h"
#include "Result.h"
#include "GrandPrixResult.h"
#include "Circuit.h"
#include <vector>
using namespace std;

class GrandPrix
{

public:
	/**
		Constructor
	*/
	GrandPrix();

	/**
		Value Constructor
	*/
	GrandPrix(Circuit *);

	/**
		Destructor
		@details Deletes the following memory:
		- The Race held by the Grand Prix
		- The Result held by the Grand Prix
		
		NOTE: Does not delete the Circuit
	*/
	~GrandPrix();

	/**
		@param teams: All of the teams that will be participating in a Grand Prix.
		@return An instance of GrandPrixResult, containing the results of the final official race of the Grand Prix.
	*/
	Result *runGrandPrix(vector<RaceTeam *> *);

	/**
		@brief Displays the results of the Grand Prix
	*/
	void displayResult();

	/**
		@brief Sets the circuit on which the Grand Prix will take place.
	*/
	void setCircuit(Circuit *);

private:
	/**
		@brief The circuit on which all of the races during this Grand Prix will take place.
	*/
	Circuit *circuit;

	/**
		@brief The race(s) that will take place during this Grand Prix. Will change state from "practice" to "qualifying" to "official" as required.
	*/
	Race *race;

	/**
		@brief The result of the Grand Prix.
	*/
	Result *result;
};

#endif