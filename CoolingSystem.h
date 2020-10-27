/**
   @file CoolingSystem.h
   @class CoolingSystem
   @authors Michael Timothy
   @version 1.0.1
   @brief The cooling system of the car. 
 */

#ifndef COOLINGSYSTEM_H
#define COOLINGSYSTEM_H

#include "CarPart.h"

class CoolingSystem: public CarPart {

	public:
		
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		CoolingSystem(float, float, float, string);

		/**
			Destructor
		*/
		~CoolingSystem();

	private:
		/**
			Constructor
		*/
		CoolingSystem();
};

#endif
