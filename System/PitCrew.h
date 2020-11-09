/**
   @file PitCrew.h
   @class PitCrew
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef PITCREW_H
#define PITCREW_H
//collegue

#include "TyreStrategy.h"
#include "PitStop.h"

class PitCrew {

	public:
	
		/**
			Constructor
		*/
		PitCrew();

		/**
			Destructor
		*/
		virtual ~PitCrew();

		/**
			
			@param pitstop
		*/
		void registerAtPitStop( PitStop* );

		/**

		*/
		int getID();


		/**

		 	@param id
		*/
		void setID(int);
		
		/**

			
		*/
		
		virtual TyreStrategy * replacePart(TyreStrategy *) = 0;
		

	protected:

		/**
			@brief 
		*/
		PitStop * myPitStop;
		
		/**
			@brief 
		*/
		int myID;
};

#endif
