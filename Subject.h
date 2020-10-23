/**
   @file Subject.h
   @class Subject
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include "RacingTeam.h"
#include "RaceState.h"

class Subject {

	public:
		
		/**
			Constructor
		*/
		Subject();

		/**
			Destructor
		*/
		~Subject();

		/**
			
			@param
		*/
		void attach( RacingTeam* );

		/**
			
			@param
		*/
		void detach( RacingTeam* );

		/**
			
			@param
		*/
		virtual void notify( RaceState* ) = 0;
		
	private:
	
		/**			
			@brief
		*/
		RacingTeam* observerList;
};

#endif
