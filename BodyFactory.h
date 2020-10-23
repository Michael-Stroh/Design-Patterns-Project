/**
   @file BodyFactory.h
   @class BodyFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef BODYFACTORY_H
#define BODYFACTORY_H

#include "CarPartFactory.h"

class BodyFactory: public CarPartFactory {

	public:
	
		/**
			Constructor
		*/
		BodyFactory();

		/**
			Destructor
		*/
		~BodyFactory();

		/**
			Creates a specific CarPart and returns the object made
			@return
		*/
		CarPart* createPart();
};

#endif
