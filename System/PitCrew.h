/**
   @file PitCrew.h
   @class PitCrew
   @authors Kayla
   @version 3.0.0
   @brief
 */


#ifndef PITCREW_H
#define PITCREW_H
 //collegue

#include "TyreStrategy.h"
#include "PitStop.h"

class PitCrew {

public:

	/**
		Constructor
	*/
	PitCrew();

	/**
		Destructor
	*/
	virtual ~PitCrew();

	/**

		@param pitstop
	*/
	void registerAtPitStop(PitStop*);

	/**
		@brief get crew member id
	*/
	int getID();


	/**

		@param id
	*/
	void setID(int);

	/**

		@brief virtual replacePart is implemented in child classes
	*/

	virtual TyreStrategy* replacePart(TyreStrategy*) = 0;

	/**

		@brief get myPitStop
	*/
	PitStop* getPitStop();


protected:

	/**
		@brief
	*/
	PitStop* myPitStop;

	/**
		@brief
	*/
	int myID;
};

#endif
