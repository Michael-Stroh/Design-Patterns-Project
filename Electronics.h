/**
   @file Electronics.h
   @class Electronics
   @authors Michael Timothy
   @version 1.0.1 
   @brief The elctronics system of the car. Its primary role will be to provide handling, acceleration
   	      and speed to the car (in the sense that the electronics system coordinates all of the parts of
   	      the car. The better it does this, the more effective )
 */


#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "CarPart.h"

class Electronics: public CarPart {

	public:
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Electronics(float, float, float, string);
		
		/**
			Destructor
		*/
		~Electronics();
	private:
		/**
			Constructor
		*/
		Electronics();

};

#endif
