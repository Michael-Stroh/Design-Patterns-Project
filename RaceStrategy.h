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
			@brief
		*/
		TyreStrategy* tyreStrategy;
		
		/**
			@brief
		*/
		PitStopStrategy* pitCrewStrategy;
		
		/**
			@brief
		*/
		DriverStrategy* driverStrategy;

};

#endif
