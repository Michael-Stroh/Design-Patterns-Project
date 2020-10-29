/**
   @file PitCrew.h
   @class PitCrew
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef PITCREW_H
#define PITCREW_H

//#include "PitStop.h"
class PitStop;			//forward declared since circular dependency

class PitCrew {

	public:
	
		/**
			Constructor
		*/
		PitCrew();

		/**
			Destructor
		*/
		~PitCrew();

		/**
			
			@param
		*/
		void registerWork( PitStop * );

		/**
			
			@param
		*/
		void setCar( int );
		
		/**
			
		*/
		virtual void update() = 0;

		/**

		*/
		bool getStatus();


		/**

		 	@param
		*/
		void getStatus( bool );

	private:

		/**
			@brief 
		*/
		PitStop * worksFor;
		
		/**
			@brief 
		*/
		bool status;
};

#endif
