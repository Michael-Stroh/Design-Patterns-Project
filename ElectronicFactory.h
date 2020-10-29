/**
   @file ElectronicFactory.h
   @class ElectronicFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the engine of a car and ensuring its variables are
   varied and set correctly.
 */


#ifndef ELECTRONICFACTORY_H
#define ELECTRONICFACTORY_H

#include "CarPartFactory.h"
#include "Electronics.h"

class ElectronicFactory: public CarPartFactory {

	public:
		
		/**
			Constructor
		*/
		ElectronicFactory();

		/**
			Destructor
		*/
		~ElectronicFactory();

		/**
			
			@return
		*/
		CarPart* createPart();
};

#endif
