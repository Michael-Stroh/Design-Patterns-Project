/**
   @file Strategies.h
   @class Strategies
   @authors Brent
   @version 1.0.0
   @brief 
 */

#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string.h>
#include <algorithm>

#include "RaceStrategy.h"
#include "LogisticsStrategy.h"
#include "Driver.h"
#include "CompositeRoad.h"

using namespace std;

class Strategies {

	public:
	
		/**
			Constructor
		*/
		Strategies();

		/**
			Constructor
			@param the driver for the race
			@param the name of the race
		*/
		void setRaceStrategy(Driver*, string name);

		/**
			Destructor
		*/
		~Strategies();
		
		/**
			
			@return
		*/
		static int getMonth();

		/**

			@param date
		*/
		void setMonth( int );
		
		/**
			create race track vector;
		*/
		void createRaces();
		
		/**
		called at the end of race for logisitics and keeping track of races
		*/
		void endOfRace(string name);
		
		/**
		returns the race strategy object
		*/
		RaceStrategy* getRaceStrategy();
		
		/**
			prints the races vector
		*/
		void print();
				
		/**
		*/
		void setLogistics();
				
		/**
		*/
		vector<RaceTrack*> getRaceTrack();
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
			@brief vector to instantate the race strategy
		*/		
		vector<RaceTrack*> races;
		
		
		
};

#endif
