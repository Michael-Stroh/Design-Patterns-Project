/**
   @file PitStopStrategy.h
   @class PitStopStrategy
   @authors Michael
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
		 	@param tyreStart
		 	@param Tyre Startergy
		*/
		PitStopStrategy( TyreStrategy* );

		/**
			Destructor
		*/
		~PitStopStrategy();

		/**
			
			@return
			@brief checks to see if the lap is a pit lap
			@param int current lap
			@return true if pit is needed 
		*/
		bool CheckForPitStop();
		bool CheckForPitStop(int);

		/**
			
			@brief calls a pitstop 
		*/
		void CallPitStop();
		

		/**

		*/
		void IncrementLap();
		//void IncrementLap();
		
		/**
			
			@param laps
		*/
		void setLap( int );
		//void setLap( int );
		
		/**
			
			@return
		*/
		int getLap() const;
		//int getLap() const;
		
	private:

		/**
			@brief
			@brief holds the tyre object
		*/
		TyreStrategy* tyres;

		/**
			@brief
		*/
		int currentLap;

		/**
			@brief
			@brief holds the pit stop object
		*/
		PitStop* ps;
};

#endif
















