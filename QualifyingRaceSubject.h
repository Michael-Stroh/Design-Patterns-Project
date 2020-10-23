/**
   @file QualifyingRaceSubject.h
   @class QualifyingRaceSubject
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef QUALIFYINGRACESUBJECT_H
#define QUALIFYINGRACESUBJECT_H

#include "Subject.h"
#include "RaceState.h"

class QualifyingRaceSubject: public Subject {

	public:
	
		/**
			Constructor
		*/
		QualifyingRaceSubject();

		/**
			Destructor
		*/
		~QualifyingRaceSubject();

		/**
			
			@param
		*/
		void notify( RaceState* );
};

#endif
