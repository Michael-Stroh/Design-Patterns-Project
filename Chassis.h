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
			Constructor
		*/
		Chassis();

		/**
			Constructor
		*/
		~Chassis();

		/**
			Displays the detials of the object
		*/
		void print();
};

#endif
