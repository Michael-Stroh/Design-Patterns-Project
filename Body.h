/**
   @file Body.h
   @class Body
   @authors Michael Timothy
   @version 1.0.1
   @brief The body of the car. Need to fill in its exact details at a later point
   @warning Make sure the brief was updated
 */

#ifndef BODY_H
#define BODY_H

#include "CarPart.h"

class Body: public CarPart {

	public:
	
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Body(float, float, float, string);


		/**
			Destructor
		*/
		~Body();

	private:
		/**
			Constructor
		*/
		Body();

};

#endif
