/**
   @file Chassis.h
   @class Chassis
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CHASSIS_H
#define CHASSIS_H

#include "CarPart.h"

class Chassis: public CarPart {


	public:
	
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param n is the name of the part
			@param b is the brand of the part
		*/
		Chassis(float, float, float, string, string);

		/**
			Constructor
		*/
		~Chassis();

	private:
		/**
			Default Constructor
		*/
		Chassis();
};

#endif
