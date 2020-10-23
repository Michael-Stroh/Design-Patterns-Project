/**
   @file SteeringFactory.h
   @class SteeringFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef STEERINGFACTORY_H
#define STEERINGFACTORY_H

#include "CarPartFactory.h"
#include "CarPart.h"

class SteeringFactory: public CarPartFactory {


	public:
		
		/**
			Constructor
		*/
		SteeringFactory();

		/**
			Destructor
		*/
		~SteeringFactory();

		/**
			
			@return
		*/
		CarPart* createPart();
};

#endif
