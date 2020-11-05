/**
   @file GrandPrix.h
   @class GrandPrix
   @authors Alex Michael
   @version 1.3.0
   @brief Responsible for running the practice, qualifying & official races that take place on a specific circuit during a Grand Prix. 
   @todo: Add prepare/cleanup for race (tie in with observer, race subject)
   @todo: Finish circuit populate( will finish soon )
 */

#ifndef GRAND_PRIX_H
#define GRAND_PRIX_H

#include "GrandPrixResult.h"
#include "RaceResult.h"
#include "RaceTrack.h"
#include "RaceTeam.h"
#include "Race.h"
#include <fstream>

class RaceTeam;
class Race;

class GrandPrix {

	public:
		/**
			Constructor
		*/
		GrandPrix();

		/**
			Value Constructor
		 	@param track: The given RaceTrack for the GrandPrix
		*/
		GrandPrix( RaceTrack* );

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
		Result* runGrandPrix( vector< RaceTeam* >);

		/**
			@brief Reads data from the given file to be able to create the Circuit
			@param fileName
		*/
		static void populateCircuit( const string& );

		/**
			@brief Displays the results of the Grand Prix
		*/
		void displayResult();

		/**
			@brief Sets the circuit on which the Grand Prix will take place.
		*/
		void setCircuit( Circuit* );


	private:

		/**
			@brief The circuit on which all of the races during this Grand Prix will take place.
		*/
		RaceTrack* circuit;

		/**
			@brief The race(s) that will take place during this Grand Prix. Will change state from "practice" to "qualifying" to "official" as required.
		*/
		Race* race;

		/**
			@brief The result of the Grand Prix.
		*/
		Result* result;
};

#endif
