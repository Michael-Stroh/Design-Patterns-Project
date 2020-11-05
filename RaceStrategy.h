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
#include "RaceTrack.h"
#include "Circuit.h"

class RaceStrategy {
	
	public:
		
		/**
			Constructor
		 	@param drive
		 	@param track
		*/
		RaceStrategy( Driver* , RaceTrack* );

		/**
			Destructor
		*/
		~RaceStrategy();

		/**
			makes the pitstop strategy and sets it
			@param strategy
		*/
		void setPitStopStrategy( TyreStrategy* );
		

		/**
			makes the driver strategy and sets it
			@param strategy
		*/
		void setDriverStrategy( TyreStrategy* );

		/**
			makes the tyre strategy and sets it
			@param track
		*/
		void setTyreStrategy( RaceTrack* );
		
		/**
			returns the driver strategy
		*/
		DriverStrategy*  getDriverStrategy();
		
		/**
			returns the tyre strategy variable
		*/
		TyreStrategy* getTyreStrategy();
		
		/**
			set the driver
			@param drive
		*/
		void setDriver( Driver* );
		
		/**
			returns the driver that was set
		 	@return
		*/
		Driver* getDriver();
		
		/**
			returns the pitstop strategy
		*/
		PitStopStrategy* getPitStopStrategy();
		
	private:
	
		/**
			@brief the variable that holds the tyre strategy
		*/
		TyreStrategy* tyreStrategy{};
		
		/**
			@brief the variable that holds the pit crew strategy
		*/
		PitStopStrategy* pitStopStrategy{};
		
		/**
			@brief the variable that holds the driver strategy
		*/
		DriverStrategy* driverStrategy{};
		
		/**
			@brief the variable that holds the driver
		*/
		Driver* driver;
		
		/**
			@brief the variable that holds the race track
		*/
		RaceTrack* rt;
		
		/**
			@brief name of the race to keep track of what strategy is for what
		*/
		string name;

};

#endif
