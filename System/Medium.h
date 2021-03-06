/**
   @file Medium.h
   @class Medium
   @authors Brent
   @version 1.0.0
   @brief Represents a Tyre that is made out of a standard compound that provides a balance of grip and strength. 
 */


#ifndef MEDIUM_H
#define MEDIUM_H

#include <math.h>
#include <iostream>


#include "Tyre.h"

class Medium : public Tyre {

public:

	/**
		Constructor
	*/
	Medium();

	/**
		Constructor
		@param durability
		@param grip
		@param pressure
	*/
	Medium(int, int, float);

	/**
		Destructor
	*/
	~Medium();

	/**
		@brief return type of tyre
		@return string type of tyre
	*/
	string getTyreType();

	void setTyreType(string str);

	/**
		@brief to be used after every offical lap
		@param float distance of lap
	*/
	void usage(float);
private:
	string type;

};

#endif
