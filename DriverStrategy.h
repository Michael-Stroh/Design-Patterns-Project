/**
   @file DriverStrategy.h
   @class DriverStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef DRIVERSTRATEGY_H
#define DRIVERSTRATEGY_H

#include <iostream>
#include <vector>
#include <string>

#include "Driver.h"
#include "AggressiveDriving.h"
#include "ControlledDriving.h"
#include "CautiousDriving.h"

#include "TyreStrategy.h"
#include "Tyre.h"

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
			Constructor
			@param
		*/
		DriverStrategy(TyreStrategy* tyre);

		/**
			Destructor
		*/
		~DriverStrategy();

		/**
			
		*/
		void displayDriver();
		
		/**
			
		*/
		void setDriver(Driver* d);
		
		/**
			
		*/
		Driver* getDriver();
		
		/**
			
		*/
		vector<Driver*> decideStrategy();
		
		/**
		 	called when pit has happened
		*/
		void changeStrategy();
	
	private:
		/**
			@brief 
		*/
		Driver* raceDriver;
		
		/**
			@brief
		*/
		TyreStrategy* tyreStrategy;
		
		/**
			@brief front of vector is the one in current use
		*/
		vector<Driver*> drivers;
		

};

#endif
