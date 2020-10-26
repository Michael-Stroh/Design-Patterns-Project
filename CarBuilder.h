/**
   @file CarBuilder.h
   @class CarBuilder
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARBUILDER_H
#define CARBUILDER_H

#include "CarComposite.h"
#include "CarPartFactory.h"

#include <vector>

class CarBuilder {

	public:
	
		/**
			Constructor
		*/
		CarBuilder();

		/**
			Destructor
		*/
		~CarBuilder();

		/**
			Builds a car object and returns the object created
			@return
		*/
		CarComposite* buildCar();
	
	private:
		
		/**
     		@brief holds a vector of tall the factories
		*/
		vector<CarPartFactory*> factories;
};

#endif
