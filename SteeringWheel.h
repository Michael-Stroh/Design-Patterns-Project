/**
   @file SteeringWheel.h
   @class SteeringWheel
   @authors Michael Timothy
   @version 1.0.1
   @brief The steeringwheel of the car. Its primary role will be to provide steering to the car.
 */

#ifndef STEERINGWHEEL_H
#define STEERINGWHEEL_H

#include "CarPart.h"

class SteeringWheel: public CarPart {

	public:
		
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		SteeringWheel(float, float, float, string);

		
		/**
			Destructor
		*/
		~SteeringWheel();

	private:
		/**
			Constructor
		*/
		SteeringWheel();
};

#endif
