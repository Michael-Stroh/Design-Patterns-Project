/**
   @file PitStop.h
   @class PitStop
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef PITSTOP_H
#define PITSTOP_H

#include "PitCrew.h"
#include "Car.h"

class PitStop {

	public:
	
		/**
			Constructor
		*/
		PitStop();

		/**
			Destructor
		*/
		~PitStop();

		/**
			
			@param
		*/
		bool attach( PitCrew* );

		/**
			
			@param
		*/
		bool detach( PitCrew* );

		/**
			
			@param
		*/
		void notify();

		/**
			
			@param
		*/
		virtual bool setCar( Car* ) = 0;
	
	private:

		/**
			@brief 
		*/
		vector<PitCrew*> pitcrew;
};

#endif
