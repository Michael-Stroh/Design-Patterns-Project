/**
   @file RaceSubject.h
   @class RaceSubject
   @authors Alex
   @version 1.0.0
   @brief The subject for a race, used to update racing teams of any pertinent information regarding the race
 */

#ifndef RACESUBJECT_H
#define RACESUBJECT_H

#include "Subject.h"

class RaceSubject : public Subject
{

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
			
			@param An instance of RaceState, used to notify all observers of any changes
		*/
	void notify(RaceState *);
};

#endif
