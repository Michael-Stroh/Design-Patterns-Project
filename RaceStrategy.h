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
#include "PitCrewStrategy.h"
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
		void setPitCrewStrategy();

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
		PitCrewStrategy* pitCrewStrategy;
		
		/**
			@brief
		*/
		DriverStrategy* driverStrategy;

};

#endif
