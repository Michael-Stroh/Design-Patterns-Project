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
		*/
		RaceStrategy(Driver* driver, RaceTrack*  rt);

		/**
			Destructor
		*/
		~RaceStrategy();

		/**
			makes the pitstop strategy and sets it
			@param tyre strategy
		*/
		void setPitStopStrategy(TyreStrategy* ts);
		

		/**
			makes the driver strategy and sets it
			@param tyre strategy
		*/
		void setDriverStrategy(TyreStrategy* ts);

		/**
			makes the tyre strategy and sets it
			@param RaceTrack
		*/
		void setTyreStrategy(RaceTrack*  rt);
		
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
			@param the driving 
		*/
		void setDriver(Driver* d);
		
		/**
			returns the driver that was set
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
		TyreStrategy* tyreStrategy;
		
		/**
			@brief the variable that holds the pit crew strategy
		*/
		PitStopStrategy* pitStopStrategy;
		
		/**
			@brief the variable that holds the driver strategy
		*/
		DriverStrategy* driverStrategy;
		
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
