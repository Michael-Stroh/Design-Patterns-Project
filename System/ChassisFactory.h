/**
   @file ChassisFactory.h
   @class ChassisFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the chassis of a car and ensuring its variables are
   varied and set correctly.
 */

#ifndef CHASSISFACTORY_H
#define CHASSISFACTORY_H

#include "CarPartFactory.h"
#include "Chassis.h"

class ChassisFactory: public CarPartFactory {


	public:

		/**
			Constructor
		*/
		ChassisFactory();

		/**
			Destructor
		*/
		~ChassisFactory();

		/**
			Creates and returns a CarPart object
			@return
		*/
		CarPart* createPart();
};

#endif
