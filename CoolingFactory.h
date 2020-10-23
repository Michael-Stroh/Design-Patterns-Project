/**
   @file CoolingFactory.h
   @class CoolingFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef COOLINGFACTORY_H
#define COOLINGFACTORY_H

#include "CarPartFactory.h"

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
