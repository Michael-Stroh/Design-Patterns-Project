/**
   @file CautiousDriving.h
   @class CautiousDriving
   @authors Brenton
   @version 1.0.0
   @brief A concrete state for the Driver that simulates cautious driving patterns.
 */

#ifndef CAUTIOUSDRIVING_H
#define CAUTIOUSDRIVING_H

#include "Driver.h"

#include <string>
#include <iostream>

using namespace std;


class CautiousDriving : public Driver {

public:

	/**
		Constructor
	*/
	CautiousDriving();

	/**
		Constructor
	*/
	CautiousDriving(string name, float);
	/**
		Constructor
	*/
	CautiousDriving(Driver* d);

	/**
		Destructor
	*/
	~CautiousDriving();

	/**
		Displays the details of the object
		@return
	*/
	void displayDriver();

	/**
		@brief gets the type of driving
		@return string of the driving type
	*/
	string getType();



private:
	/** @brief type of the driver object*/
	string type;
};

#endif
