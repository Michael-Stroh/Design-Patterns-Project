/**
   @file EngineFactory.h
   @class EngineFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the engine of a car and ensuring its variables are
   varied and set correctly.
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
