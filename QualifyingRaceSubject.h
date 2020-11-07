/**
   @file QualifyingRaceSubject.h
   @class QualifyingRaceSubject
   @authors Alex
   @version 1.0.0
   @brief The subject for a qualifying race, used to update racing teams of any pertinent information regarding the qualifying race
 */

#ifndef QUALIFYINGRACESUBJECT_H
#define QUALIFYINGRACESUBJECT_H

#include "Subject.h"
#include "RaceState.h"

class QualifyingRaceSubject : public Subject
{

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
			
			@param: The results of a qualifying race, used to inform teams of what's going on during/after the qualifying race
		*/
	void notify( Result* );
};

#endif
