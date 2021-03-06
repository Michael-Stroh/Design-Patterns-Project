/**
   @file Logistics.h
   @class Logistics
   @authors Michael
   @authors Brent
   @version 1.0.0
   @brief A class used to create the containers needed to transport the car and other equipment to races.
 */

#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "Container.h"
#include "utilities/Logger.h"

#include <string>
#include <iostream>

using namespace std;

class Logistics {

public:
	/**
		Constructor
		@param string name of race
		@param bool if european or not
	*/
	Logistics(string, bool);



	/**
		Destructor
	*/
	~Logistics();

	/**

		@return
	*/

	string getName();

private:

	/**
		@brief
	*/
	Container* garage;

	/**
		@brief
	*/
	Container* carComponents;

	/**
		@brief
	*/
	Container* catering;

	/**
		@brief
	*/
	bool isEuropean;

	/**
		@brief
	*/
	string name;
};

#endif
