/**
   @file RaceStrategy.h
   @class RaceStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACESTRATEGY_H
#define RACESTRATEGY_H

#include "TyreStrategy.h"
#include "PitStopStrategy.h"
#include "DriverStrategy.h"

class RaceStrategy {
	
	public:
		
		/**
			Constructor
		*/
		RaceStrategy();

		/**
			Destructor
		*/
		~RaceStrategy();

		/**
			
		*/
		void setPitStopStrategy();

		/**
			
		*/
		void setDriverStrategy();

		/**
			
		*/
		void setTyreStrategy();
		
	private:
	
		/**
			@brief the variable that holds the tyre strategy
		*/
		TyreStrategy* tyreStrategy;
		
		/**
			@brief the variable that holds the pit crew strategy
		*/
		PitStopStrategy* pitCrewStrategy;
		
		/**
			@brief the variable that holds the driver strategy
		*/
		DriverStrategy* driverStrategy;

};

#endif
