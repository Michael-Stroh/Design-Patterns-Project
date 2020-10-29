/**
   @file CoolingFactory.h
   @class CoolingFactory
   @authors Michael Timothy
   @version 1.0.1 
   @brief A concrete factory responsible for creating the cooling system of a car and ensuring its variables are
   varied and set correctly.
 */

#ifndef COOLINGFACTORY_H
#define COOLINGFACTORY_H

#include "CarPartFactory.h"
#include "CoolingSystem.h"

class CoolingFactory: public CarPartFactory {

	public:
		
		/**
			Constructor
		*/
		CoolingFactory();

		/**
			Destructor
		*/
		~CoolingFactory();

		/**
			Determines what CarPart to make a returns a pointer to the object created
			@return
		*/
		CarPart* createPart();
};

#endif
