/**
   @file ChassisFactory.h
   @class ChassisFactory
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CHASSISFACTORY_H
#define CHASSISFACTORY_H

#incluide "CarPartFactory.h"

class ChassisFactory: public CarPartFactory {


	public:

		/**
			Constructor
		*/
		ChassisFactory();

		/**
			Destructor
		*/
		~ChassisFactory();

		/**
			Creates and returns a CarPart object
			@return
		*/
		CarPart* createPart();
};

#endif
