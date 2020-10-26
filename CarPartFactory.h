/**
   @file CarPartFactory.h
   @class CarPartFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARPARTFACTORY_H
#define CARPARTFACTORY_H

#include "CarPart.h"

class CarPartFactory {

	public:
	
		/**
			Constructor
		*/
		CarPartFactory();

		/**
			Destructor
		*/
		virtual ~CarPartFactory();

		/**
			Determines what CarPart to make and returns the object created
			@return
		*/
		virtual CarPart* createPart() = 0;
};

#endif
