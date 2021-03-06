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
#include "LapResult.h"
#include <algorithm>

class RaceResult : public Result {

	public:

		/**
				Constructor
		*/
		RaceResult();

		/**
			Destructor
		*/
		~RaceResult();

		/**
			@brief
			@param[in] r: An instance of LapResult, to be added to the total results of the race
		*/
		void addResult( Result* );

		/**
			@brief Prints the formatted results of the race
		*/
		void print();

		/**
			@brief Prints the formatted grid positions for the race (if the race was a qualifying race)
		*/
		void printGridPositions();

		/**
			@brief Checks whether or not the driver has obtained a grid
		*/
		bool driverHasGridPosition( string );

		/**
			@brief Places the bottom X drivers without grid positions on the grid
		*/
		void placeBottomXOnGrid( int );

		/**
			@brief Applies the 107% rule to the qualifying drivers
		*/
		void apply107Rule();

		/**
			@brief Returns the vector containing the drivers and their respective positions
		*/
		vector< pair< string, int>> getDriverGridPositions();

		/**
			@brief Returns a vector containing the driver's names & their position in the race
		*/
		vector< pair< string, int>> getDriverResults();

		/**
			@brief Returns a vector containing the driver's names & their points earned in the race
		*/
		vector< pair< string, int>> getDriverPoints();

		/**
			@brief Returns a vector containing the teams and the points they earned in the race
		*/
		vector< pair< string, int>> getTeamPoints();

		/**
			@brief Returns whether or not a driver has qualified for the current qualifying race
		*/
		bool isQualified(string);

		/**
			@brief Returns the drivers performance in the current race
			@details: Returns a value from 0 to 1, 1 meaning they're first in the race & 0 meaning they're last
		*/
		float getDriverPerformanceRating(string);

	private:
		/**
			@brief A collection of all the lapresults for the current race
		*/
		vector< Result* > lapResults;

		/**
			@brief A collection of all the lapresults for the drivers for the current race
		*/
		vector< pair< string, float>> totalDriversLaptime;

		/**
			@brief A collection of the fastest laptime for the drivers for the current race
		*/
		vector< pair< string, float>> driversFastestLaptime;

		/**
			@brief A vector containing the drivers and their grid positions
		*/
		vector< pair< string, int>> driverGridPositions;

		/**
			@brief A vector containing the drivers and their points
		*/
		vector< pair< string, int>> driverPoints;

		/**
			@brief A vector containing the drivers and their respective teams
		*/
		vector< pair< string, string>> driversTeams;

		/**
			@brief A helper function to sort the drivers in ascending order based on their laptimes
		*/
		void sortDrivers();

		/**
			@brief Removes the driver with the provided name from the grid
		*/
		void removeDriverFromGrid( string driverName );

		/**
			@brief Reassigns the grid positions, filling in gaps left by the 107 rule
		*/
		void reassignGridPositions();

		/**
			@brief Returns the team that a driver is driving for
		*/
		string getDriverTeam( string );

		/**
			@brief holds the position for the fastest lap
		*/
		float polePositionFastestLap;

};

#endif
