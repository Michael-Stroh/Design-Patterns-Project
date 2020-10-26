/**
   @file CarTransport.h
   @class CarTransport
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARTRANSPORT_H
#define CARTRANSPORT_H

#include "LogisiticsStrategy.h"
#include "Car.h"

class CarTransport {

	public:
		
		/**
			Constructor
		*/
		CarTransport();

		/**
			Destructor
		*/
		~CarTransport();

		/**
			Displays that the car is being moved to the factory
		*/
		void transportCarToFactory();

		/**
			Displays that the car is being moved to the factory
		*/
		void transportCarToRace();

private:
	
};

#endif
