/**
   @file BrakesFactory.h
   @class BrakesFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the brakes of a car and ensuring its variables are
   varied and set correctly.
 */

#ifndef BRAKESFACTORY_H
#define BRAKESFACTORY_H

#include "CarPartFactory.h"

class BrakesFactory: public CarPartFactory {

	public:
		
		/**
			Constructor
		*/
		BrakesFactory();

		/**
			Destructor
		*/
		~BrakesFactory();

		/**
			Creates a specific CarPart and returns the object made
			@return
		*/
		CarPart* createPart();
};

#endif
