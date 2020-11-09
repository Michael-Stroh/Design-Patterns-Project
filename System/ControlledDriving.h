/**
   @file ControlledDriving.h
   @class ControlledDriving
   @authors Brenton
   @version 1.0.0
   @brief
 */

#ifndef CONTROLLEDDRIVING_H
#define CONTROLLEDDRIVING_H

#include "Driver.h"

#include <string>
#include <iostream>

using namespace std;
class ControlledDriving : public Driver {

public:

	/**
		Constructor
	*/
	ControlledDriving();

	/**
		Constructor
	*/
	ControlledDriving(string name, float);

	/**
		Constructor
	*/
	ControlledDriving(Driver* D);

	/**
		Destructor
	*/
	~ControlledDriving();

	/**
		Displays the details of the driver
		@return
	*/
	void displayDriver();

	/**
		@brief gets the type of driving
		@return the type of driver
	*/
	string getType();


private:
	/** @brief type of the driver object*/
	string type;
};

#endif
