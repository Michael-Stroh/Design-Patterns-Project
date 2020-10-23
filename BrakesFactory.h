/**
   @file BrakesFactory.h
   @class BrakesFactory
   @authors Michael
   @version 1.0.0
   @brief 
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
