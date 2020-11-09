/**
   @file DriverStrategy.h
   @class DriverStrategy
   @authors Brenton
   @version 1.0.0
   @brief
 */


#ifndef DRIVERSTRATEGY_H
#define DRIVERSTRATEGY_H

#include <iostream>
#include <vector>
#include <string>

#include "Driver.h"
#include "AggressiveDriving.h"
#include "ControlledDriving.h"
#include "CautiousDriving.h"

#include "TyreStrategy.h"
#include "Tyre.h"

using namespace std;

class DriverStrategy {

public:

	/**
		@brief Constructor of driver strategy
	*/
	DriverStrategy();

	/**
		@brief Constructor
		@param driver object
	*/
	DriverStrategy(Driver*);


	/**
		@brief Constructor
		@param tyrestrategy
	*/
	DriverStrategy(TyreStrategy* tyre);

	/**
		@brief Destructor
	*/
	~DriverStrategy();

	/**
		@brief displays all drivers and the scheduled plan
	*/
	void displayDriver();

	/**
		@brief changes the raceDriver to d
		@param driver object to clone
	*/
	void setDriver(Driver* d);

	/**
		@brief returns the driver
		@return driver object
	*/
	Driver* getDriver();

	/**
		@brief makes the drivers strategy depending on the tyre type
		@return a vector of drivers all with different types to be ready to change during pitstops
	*/
	vector<Driver*> decideStrategy();

	/**
		@brief called when pit has happened and reverts back the driver to the orginal plan
	*/
	void changeStrategy();

	/**
		@brief changes the driver strategy to whatever the param is set
		@param string type
	*/
	void changeStrategy(string);

	/**
		@brief changes the drivers aggression level based on how it preformed in the race
		@param bool value decides if lap is good or bad;
	*/
	void lapChanges(bool);

	/**
	* @brief changes the level of aggression depending on results
	* @param the amount to change can be negative or postive
	*/

	void changeAggressionDueToPositions(int);

private:
	/**
		@brief the orginal driver
	*/
	Driver* raceDriver;

	/**
		@brief tyrestrategy
	*/
	TyreStrategy* tyreStrategy;

	/**
		@brief front of vector is the one in current use
	*/
	vector<Driver*> drivers;


};

#endif
