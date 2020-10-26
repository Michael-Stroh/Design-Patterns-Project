/**
   @file PitStopStrategy.h
   @class PitStopStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef PITSTOPSTRATEGY_H
#define PITSTOPSTRATEGY_H

class PitStopStrategy {

	public:
	
		/**
			Constructor
		*/
		PitStopStrategy();

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
};

#endif
