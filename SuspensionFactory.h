/**
   @file SuspensionFactory.h
   @class SuspensionFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the suspension of a car and ensuring its variables are
   varied and set correctly.
*/

#ifndef SUSPENSIONFACTORY_H
#define SUSPENSIONFACTORY_H

#include "CarPartFactory.h"
#include "Suspension.h"

class SuspensionFactory: public CarPartFactory {

	public:
	
		/**
			Constructor
		*/
		SuspensionFactory();

		/**
			Destructor
		*/
		~SuspensionFactory();

		/**
			
			@return
		*/
		CarPart* createPart();
};

#endif
