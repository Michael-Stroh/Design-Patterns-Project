/**
   @file CarPartFactory.h
   @class CarPartFactory
   @authors Michael Timothy
   @version 1.0.1 
   @brief An interface that all Concrete Factories will have ti implement in order to create CarParts.
 */

#ifndef CARPARTFACTORY_H
#define CARPARTFACTORY_H

#include "CarPart.h"
#include <string>
#include<cstdlib>
#include <ctime>

class CarPartFactory {

	public:
	
		/**
			Constructor
		*/
		CarPartFactory();

		/**
			Destructor
		*/

		virtual ~CarPartFactory();

		/**
			Determines what CarPart to make and returns the object created
			@return
		*/
		virtual CarPart* createPart() = 0;

	protected:

		/**
			@brief A list of all the possible brands/companies that produce car parts.
		*/
		const static string brands [];

		/**
			@brief The number of elements int eh brands array
		*/
		const static int numBrands;

		/**
			@brief Generates the brand name of a car part using the brands array
			@return a randomly selected string from the brands array
		*/
		string generateBrandName();
		/**
			@brief Helper function for generating random numbers.
			@return a random float between -1.0 and 1.0
		*/
		float generateRandomFraction();
		
};

#endif
