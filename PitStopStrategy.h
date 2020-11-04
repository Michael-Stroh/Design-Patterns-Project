/**
   @file PitStopStrategy.h
   @class PitStopStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef PITSTOPSTRATEGY_H
#define PITSTOPSTRATEGY_H

#include <iostream>

#include "TyreStrategy.h"
#include "Tyre.h"
#include "PitStop.h"

using namespace std;

class PitStopStrategy {

	public:
	
		/**
			Constructor
		*/
		PitStopStrategy(TyreStrategy* tyre);

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
			

		*/
		void setLap(int laps);
		
		/**
			

		*/
		int getLap();
		
	private:
		TyreStrategy* tyres;
		int currentLap;
		PitStop* ps;
};

#endif
















