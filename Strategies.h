/**
   @file Strategies.h
   @class Strategies
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "RaceStrategy.h"
#include "LogisticStrategy.h"

class Strategies {

	public:
	
		/**
			Constructor
		*/
		Strategies();


		/**
			Destructor
		*/
		~Strategies();

		/**
			
			@return
		*/
		int getLapNumber();
		
	private:
	
		/**
			@brief
		*/
		RaceStrategy* raceStrategy;
		
		/**
			@brief
		*/
		LogisticStrategy* logisiticStrategy;
		
		/**
			@brief
		*/
		int lapNumber;
};

#endif
