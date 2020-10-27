/**
   @file Suspension.h
   @class Suspension
   @authors Michael Timothy
   @version 1.0.1
   @brief The suspension of the car. Its primary role will be to provide a balance of speed, handling and acceleration
*/

#ifndef SUSPENSION_H
#define SUSPENSION_H

#include "CarPart.h"

class Suspension: public CarPart {


	public:
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Suspension(float, float, float, string);

		/**
			Destructor
		*/
		~Suspension();

	private:
		/**
			Constructor
		*/
		Suspension();
};

#endif
