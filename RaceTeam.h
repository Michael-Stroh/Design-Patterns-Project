/**
   @file Racing_Team.h
   @class Racing_Team
   @authors Michael
   @version 1.0.0
   @brief 
   @todo: Implement constructor
   @todo: Implement destructor
   @todo: Implement performLap(int, circuit) with int for driver index and circuit for driving on
   @todo: Implement updateSeasonResult()
   @todo: Implement informGrandPrixs()
   @todo: Implement updateQualifyingResult()
   @todo: Implement updateOfficialResult()
   @todo: Implement setRaceState()
   @todo: Implement performLap()
   @todo: Implement setRaceState()
   @todo: Implement getDriver()
 */

#ifndef RACING_TEAM_H
#define RACING_TEAM_H

#include "RaceResult.h"
#include "RaceSeasonResult.h"
#include "Driver.h"
#include "CarComposite.h" //changed from include Car.h by Tim
#include "CarBuilder.h"
#include "Strategies.h"
#include "LapResult.h"
#include "Circuit.h"
#include <vector>
using namespace std;

class GrandPrix;
class RaceState;

class RaceTeam
{

public:
	/**
			Constructor
		*/
	RaceTeam();

	/**
			Destructor
		*/
	~RaceTeam();

	/**
	 		@brief: The method that will handle the team performing a lap on the circuit with a specific driver
			@param[in]: int: The index of the driver to be performing the lap
			@param[in]: Circuit*: The circuit on which the lap will take place
			@return: The results of the lap
		*/
	LapResult *performLap(int, Circuit *);

	/**
			@brief: Sets the internal representation of the entire season's result
			@details: Only needs to be notified once, the pointer is then updated accordingly
			@param[in]: The current season's result
		*/
	void informSeasonResult(Result *);

	/**
			@brief: Updates the internal representation of the qualifying race's result, so that the team can adjust its strategy accordingly
			@param[in]: The current (qualifying) race's result
		*/
	void updateQualifyingRaceResult(Result *);

	/**
	 		@brief: Updates the internal representation of the official race's result, so that the team can adjust its strategy accordingly
			@param[in]: The current (official) race's result
		*/
	void updateOfficialRaceResult(Result *);

	/**
			@brief: Updates the internal representation of all the GrandPrixs, so that the team can prepare
			@param[in]: A vector containing all GrandPrixs that will occur in a season
		*/
	void informGrandPrixs( vector< GrandPrix* > );

	/**
			@brief: Updates the internal representation of the state of the current race
			@param[in]: The state that the team should be informed of
		*/
	void setRaceState(RaceState*);

	/**
			@brief: Returns a pointer to a driver at index i
			@param[in]: The index of the driver to be returned
		*/
	Driver *getDriver(int);

private:
	/**
			@brief: A vector containing all the grand prixs that will take place during a season
		*/
	vector<GrandPrix *> grandPrixs;

	/**
			@brief: A vector containing the 2 drivers that drive per team
		*/
	vector<Driver *> drivers;

	/**
			@brief: The internal representation of the results of the current official race
		*/
	Result *officialRaceResult;

	/**
			@brief: The internal representation of the results of the current qualifying race
		*/
	Result *qualifyingRaceResult;

	/**
			@brief: The internal representation of the results of the current season
		*/
	Result *seasonResult;

	/**
			@brief: 
			@todo: Provide details on car member variable
		*/
	CarComposite *car;

	/**
			@brief
			@todo: Provide details on the builder member variable

		*/
	CarBuilder *builder;

	/**
			@brief
			@todo: Provide details on the strategy member variable

		*/
	Strategies *Strategy;
};

#endif
