/**
   @file SteeringFactory.h
   @class SteeringFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the steering wheel of a car and ensuring its variables are
   varied and set correctly.
 */

#ifndef STEERINGFACTORY_H
#define STEERINGFACTORY_H

#include "CarPartFactory.h"
#include "SteeringWheel.h"

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
