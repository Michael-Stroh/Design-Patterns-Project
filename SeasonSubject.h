/**
   @file SeasonSubject.h
   @class SeasonSubject
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SEASONSUBJECT_H
#define SEASONSUBJECT_H

#include "Subject.h"

class SeasonSubject: public Subject {

	public:
		
		/**
			Constructor
		*/
		SeasonSubject();

		/**
			Constructor
		*/
		~SeasonSubject();

		/**
			Constructor
		*/
		void notify( RaceState* );
};

#endif
