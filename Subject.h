/**
   @file Subject.h
   @class Subject
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SUBJECT_H
#define SUBJECT_H

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
		void attach( RaceTeam* );

		/**
			
			@param
		*/
		void detach( RaceTeam* );

		/**
			
			@param
		*/
		virtual void notify( RaceState* ) = 0;
		
	private:
	
		/**			
			@brief
		*/
		RaceTeam* observerList;
};

#endif
