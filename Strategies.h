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
#include "LogisticsStrategy.h"
#include "Driver.h"
#include "CompositeRoad.h"


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
		Strategies( RaceStrategy*, LogisticsStrategy* );

		/**
			Destructor
		*/
		~Strategies();
		
		/**
			
			@return
		*/
		int getMonth();

		/**

			@param
		*/
		void setMonth( int );

	private:
	
		/**
			@brief
		*/
		RaceStrategy* raceStrategy;
		
		/**
			@brief
		*/
		LogisticsStrategy* logisticsStrategy;
		
		/**
			@brief
		*/		
		int month;
};

#endif
