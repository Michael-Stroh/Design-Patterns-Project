/**
   @file RaceSubject.h
   @class RaceSubject
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACESUBJECT_H
#define RACESUBJECT_H

#include "Subject.h"

class RaceSubject: public Subject {

	public:
	
		/**
			Constructor
		*/
		RaceSubject();

		/**
			Destructor
		*/
		~RaceSubject();

		/**
			
			@param
		*/
		void notify( RaceState* );
};

#endif
