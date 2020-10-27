/**
   @file Brakes.h
   @class Brakes
   @authors Michael Timothy
   @version 1.0.1
   @brief The brakes of the car. Its priary role will be to provide handling to the car.
 */

#ifndef BRAKES_H
#define BRAKES_H

#include "CarPart.h"

class Brakes: public CarPart {

	public:
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Brakes(float, float, float, string);

		/**
			Destructor
		*/
		~Brakes();
	private:
		/**
			Constructor
		*/
		Brakes();

};

#endif
