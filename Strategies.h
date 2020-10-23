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
			Constructor
			@param
			@param
		*/
		Strategies( RaceStrategy*, LogisticStrategy* );

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
		LogisticStarategy* logisiticStrategy;
		
		/**
			@brief
		*/
		int lapNumber;
};

#endif
