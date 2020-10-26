/**
   @file SuspensionFactory.h
   @class SuspensionFactory
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef SUSPENSIONFACTORY_H
#define SUSPENSIONFACTORY_H

#include "CarPartFactory.h"

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
