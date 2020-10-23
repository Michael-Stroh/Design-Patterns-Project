/**
   @file DriverStrategy.h
   @class DriverStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef DRIVERSTRATEGY_H
#define DRIVERSTRATEGY_H

#include "Driver.h"

class DriverStrategy {

	public:
	
		/**
			Constructor
		*/
		DriverStrategy();

		/**
			Constructor
			@param
		*/
		DriverStrategy( Driver* );

		/**
			Destructor
		*/
		~DriverStrategy();

		/**
			
		*/
		void displayDriver();
	
	private:
		/**
			@brief 
		*/
		Driver* raceDriver;

};

#endif
