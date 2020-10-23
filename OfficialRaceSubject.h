/**
   @file OfficialRaceSubject.h
   @class OfficialRaceSubject
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef OFFICIALRACESUBJECT_H
#define OFFICIALRACESUBJECT_H

#include "Subject.h"

class OfficialRaceSubject: public Subject {

	public:
	
		/**
			Constructor
		*/
		OfficialRaceSubject();

		/**
			Destructor
		*/
		~OfficialRaceSubject();

		/**
			Constructor
			@param
		*/
		void notify( RaceState* );
};

#endif
