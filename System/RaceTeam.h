/**
   @file RaceTeam.h
   @class RaceTeam
   @authors Michael Timothy 
   @version 1.0.0
   @brief Represents a Racing Team unit. Holds all of the corresponding Engineering, Driver and Strategy components. 
 */

#ifndef RACING_TEAM_H
#define RACING_TEAM_H

#include "RaceResult.h"
#include "RaceSeasonResult.h"
#include "Driver.h"
#include "CarComposite.h" //changed from include Car.h by Tim
#include "EngineeringCrew.h"
#include "CarBuilder.h"
#include "Strategies.h"
#include "LapResult.h"
#include "Circuit.h"
#include "Strategies.h"
#include "RaceStrategy.h"
#include "DriverStrategy.h"
#include "TyreStrategy.h"
#include "Tyre.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
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
	 	@brief: Value constructor taking a string as a teamname (for testing purposes only)
	*/
	RaceTeam(string);

	/**
	@brief brents constructor idea, nice to have team name and drivers name
	*/
	RaceTeam(string teamName, vector<Driver*> d);

	/**
			Destructor
		*/
	~RaceTeam();

	/**
	 		@brief: The method that will handle the team performing a lap on the circuit with a specific driver
			@param[in]: int: The index of the driver and car to be performing the lap
			@param[in]: Circuit*: The circuit on which the lap will take place
			@return: The results of the lap
		*/
	LapResult *performLap(int, RaceTrack*);

	/**
		@brief A function to be called inside of the performaLap function. It takes in a circuit and , based on the circuits description
		and the statistics of the car at index i, determines how well the car performs relative to the best time for this circuit.
		@param[in]: int: the index of the car to perform the lap.
		@param[in]: circuit: the circuit on which the lap must be run.
	*/
	float getCarLapTime(int , RaceTrack*);

	/**
		@brief Brent
	*/
	float getDriverLapTime(int, RaceTrack*);

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
			@warning Brent
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

	/**
		@brief 
	*/
	void prepareForNextRace();

	/**
		@brief FOR TIM TO IMPLEMENT AND ADD TO MAIN MAYBE!!
	*/
	void startRace(); //reset lapcount

	/**
		@brief FOR TIM TO IMPLEMENT AND ADD TO MAIN MAYBE!!
	*/
	void endRace(); //reset lap count

	/**
	@brief Brent go wild
	@param driver
	*/
	void changeStrategiesBasedOnPosition(Driver* d, int index);

	/**
		@brief Brent used ot decide the strategy the team will use for the next grandprix
	*/
	void decideNextStrategy(GrandPrix *);

	/**
		@brief for brent to do logistics calculations
		@brief to signal the end of a race and sort of the logistics
		@param the name of the race
	*/
	void endOfGrandPrix(string);

	/**
		@brief Returns the team's name for identification and testing purposes
	*/
	string getName();

	/**
		@brief returns the car used in the most recent race by this Team.
		@return a CarComposite from this Team's EngineeringCrew
	*/
	CarComposite* getCar();

	private:


	int lapCount;

	/**
		
	*/
     RaceState * raceState;

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
	Result * officialRaceResult;

	/**
			@brief: The internal representation of the results of the current qualifying race
		*/
	Result *qualifyingRaceResult;

	/**
			@brief: The internal representation of the results of the current season
		*/
	Result *seasonResult;

	/**
			@brief
	*/
	Strategies *Strategy;

	/**
		@brief a vector of all of the Engineering Departments that will work on the car throughout the year.
	*/
	EngineeringCrew * engineeringCrew;

	/**
		@brief: A string containing the name of the team for identification during testing
	*/
	string teamName;
};

#endif
