/**
   @file PitStopStrategy.h
   @class PitStopStrategy
   @authors Brent
   @version 1.0.0
   @brief 
 */


#ifndef PITSTOPSTRATEGY_H
#define PITSTOPSTRATEGY_H

#include "TyreStrategy.h"
#include "PitStop.h"

class PitStopStrategy {

	public:

		/**
				Constructor
		*/
		PitStopStrategy( );

		/**
			Constructor
		 	@param Tyre Startergy
		*/
		PitStopStrategy( TyreStrategy* );

		/**
			Destructor
		*/
		~PitStopStrategy();

		/**
			@brief checks to see if the lap is a pit lap
			@param int current lap
			@return true if pit is needed 
		*/
		bool CheckForPitStop(int);

		/**
			@brief calls a pitstop 
		*/
		void CallPitStop();

		/**

		*/
		//void IncrementLap();
		
		/**
			
			@param laps
		*/
		//void setLap( int );
		
		/**
			
			@return
		*/
		//int getLap() const;
		
	private:

		/**
			@brief holds the tyre object
		*/
		TyreStrategy* tyres;

		/**
			@brief holds the pit stop object
		*/
		PitStop* ps;
};

#endif
















