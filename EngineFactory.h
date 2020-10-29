/**
   @file EngineFactory.h
   @class EngineFactory
   @authors Michael Timothy
   @version 1.0.2
   @brief A concrete factory responsible for creating the engine of a car and ensuring its variables are
   varied and set correctly.
 */


#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "CarPartFactory.h"
#include "Engine.h"


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
			
			@brief Creates a car engine according to the given statistics and variance for each statistic
			as specified in the Engine class.
			@return an Engine pointer.
		*/
		CarPart* createPart();


};

#endif
