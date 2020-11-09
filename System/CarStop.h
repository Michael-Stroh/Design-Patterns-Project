/**
   @file CarStop.h
   @class CarStop
   @authors Michael
   @version 1.0.0
   @brief Holds the name of the PitStop to identify which team should be using a certain pitstop.

 */

#ifndef CARSTOP_H
#define CARSTOP_H

#include "PitStop.h"

#include <string>

class CarStop : public PitStop {

public:

	/**
		Constructor
	*/
	CarStop();

	/**
		Constructor
		@param CarStopName
	*/
	CarStop(string);

	/**
		Destructor
	*/
	~CarStop();

	/**
	gets name to the parameter and indicates if it was successful
		@return
	*/
	string getName();

	/**
		Sets name to the parameter and indicates if it was successful
		@param CarName
		@return
	*/
	void setName(string);



private:

	/**
		@brief Stores the name of the CarStop object
	*/
	string name;
};

#endif
