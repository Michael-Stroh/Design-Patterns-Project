/**
   @file Transmission.h
   @class Transmission
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include "CarPart.h"

class Transmission: public CarPart {

	public:

		/**
			Constructor
		*/
		~Transmission();


		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Transmission(float, float, float, string);

	private:
		/**
			Constructor
		*/
		Transmission();

};

#endif
