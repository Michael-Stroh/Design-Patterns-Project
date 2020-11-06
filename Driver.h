/**
   @file Driver.h
   @class Driver
   @authors Brenton
   @version 1.0.0
   @brief
 */

#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>

using namespace std;

class Driver {

public:

	/** Constructors*/
	Driver();
	/**
		Constructor
		@param name
		@param aggression
		@param error prone
	*/
	Driver(string, int, float);

	/**
		Destructor
	*/
	~Driver();



	/**

		@return the name of driver
	*/
	string getName();

	/**

		@param string name of driver
	*/
	void setName(string);

	/**

		@return int aggression
	*/
	int getAggression();

	/**

		@param int aggression
	*/
	void setAggression(int);

	/**

		@return float error prone
	*/
	float getErrorProne();

	/**
		@param float error prone
	*/
	void setErrorProne(float);

	/**
		@brief prints out the driver values
	*/
	virtual void displayDriver() = 0;
	/**
		@brief returns the type
	*/
	virtual string getType() = 0;

private:

	/**
		@brief name of the driver
	*/
	string name;

	/**
		@brief aggression of the driver
	*/
	int aggression;

	/**
		@brief error occurence of the driver
	*/
	float error;
};

#endif
