/**
   @file Hard.h
   @class Hard
   @authors Brenton
   @version 1.0.0
   @brief Represents a Tyre that is made out of a harder, more durable compound.
 */


#ifndef HARD_H
#define HARD_H

#include "Tyre.h"
#include <math.h>
#include <iostream>

using namespace std;

class Hard : public Tyre {

public:

	/**
		Constructor
	*/
	Hard();

	/**
		Constructor
		@param durability
		@param grip
		@param pressure
	*/
	Hard(int, int, float);

	/**
		Desstructor
	*/
	~Hard();

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
