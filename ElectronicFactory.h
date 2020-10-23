/**
   @file ElectronicFactory.h
   @class ElectronicFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ELECTRONICFACTORY_H
#define ELECTRONICFACTORY_H

#include "CarPartFactory.h"

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
