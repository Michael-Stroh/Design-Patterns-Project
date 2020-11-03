/**
   @file SeasonSubject.h
   @class SeasonSubject
   @authors Alex
   @version 1.0.0
   @brief The subject for a season, used to update racing teams of any pertinent information regarding the season
 */

#ifndef SEASONSUBJECT_H
#define SEASONSUBJECT_H

#include "Subject.h"

class SeasonSubject : public Subject
{

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
			@param: A vector containing all of the grand prixs for a season, used to inform the RaceTeams of the grandPrixs before the season starts
		*/
	void notify(vector<GrandPrix *>);
};

#endif
