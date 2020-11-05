/**
   @file BodyFactory.h
   @class BodyFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the body of a car and ensuring its variables are
   varied and set correctly.
 */

#ifndef BODYFACTORY_H
#define BODYFACTORY_H

#include "CarPartFactory.h"
#include "Body.h"

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
