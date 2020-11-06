/**
   @file AggressiveDriving.h
   @class AggressiveDriving
   @authors Brenton
   @version 1.0.0
   @brief
 */

#ifndef AGGRESSIVEDRIVING_H
#define AGGRESSIVEDRIVING_H

#include "Driver.h"
#include <string>
#include <iostream>

using namespace std;

class AggressiveDriving : public Driver {

public:

	/**
		@brief Constructor
	*/
	AggressiveDriving();

	/**
		@brief Constructor
	*/
	AggressiveDriving(string name, float error);

	/**
		@brief Constructor
	*/
	AggressiveDriving(Driver* d);

	/**
		@brief Destructor
	*/
	~AggressiveDriving();

	/**
		@brief Display the details of the driver
		@return
	*/
	void displayDriver();

	/**
		@brief get the type of the of the driver object
		@return the type
	*/
	string getType();

private:

	/** @brief type of the driver object*/
	string type;
};

#endif
