/**
   @file OfficialRaceSubject.h
   @class OfficialRaceSubject
   @authors Alex
   @version 1.0.0
   @brief The subject for an official race, used to update racing teams of any pertinent information regarding the official race
 */

#ifndef OFFICIALRACESUBJECT_H
#define OFFICIALRACESUBJECT_H

#include "Subject.h"

class OfficialRaceSubject : public Subject
{

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
			@param: The results of an official race, used to inform teams of what's going on during/after the race
		*/
	void notify(Result *);

	/**
		@brief
	*/
	void notify(RaceState *);			//added By Tim to make this non pure virtual class
};

#endif
