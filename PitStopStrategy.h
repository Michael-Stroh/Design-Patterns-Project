/**
   @file PitStopStrategy.h
   @class PitStopStrategy
   @authors Michael
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
		*/
		PitStopStrategy( TyreStrategy* );

		/**
			Destructor
		*/
		~PitStopStrategy();

		/**
			
			@return
		*/
		bool CheckForPitStop();

		/**
			
		*/
		void CallPitStop();
		
		/**

		*/
		void IncrementLap();
		
		/**
			
			@param laps
		*/
		void setLap( int );
		
		/**
			
			@return
		*/
		int getLap();
		
	private:

		/**
			@brief
		*/
		TyreStrategy* tyres;

		/**
			@brief
		*/
		int currentLap;

		/**
			@brief
		*/
		PitStop* ps;
};

#endif
















