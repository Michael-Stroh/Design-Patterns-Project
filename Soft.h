/**
   @file Soft.h
   @class Soft
   @authors Brenton
   @version 1.0.0
   @brief Represents a Tyre that is made out of a softer compound that provides more grip.
 */

#ifndef SOFT_H
#define SOFT_H


#include <math.h>
#include <iostream>

using namespace std;

#include "Tyre.h"

class Soft : public Tyre {

public:

	/**
		Constructor
	*/
	Soft();

	/**
		@brief Constructor
		@param durability
		@param grip
		@param pressure
	*/
	Soft(int, int, float);

	/**
		Destructor
	*/
	~Soft();

	string getTyreType();

	/**
		@brief to be used after every offical lap
		@param float distance of lap
	*/
	void usage(float);

	/**
	*/
	void setTyreType(string str);

private:
	string type;

};

#endif
