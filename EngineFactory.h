/**
   @file EngineFactory.h
   @class EngineFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "CarPartFactory.h"
#include "CarPart.h"

class EngineFactory: public CarPartFactory {

	public:
		
		/**
			Constructor
		*/
		EngineFactory();

		/**
			Destructor
		*/
		~EngineFactory();

		/**
			
			@param
		*/
		CarPart* createPart();
};

#endif
