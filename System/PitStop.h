/**
   @file PitStop.h
   @class PitStop
   @authors Kayla
   @version 3.0.0
   @brief Keeps track of the different kinds of concrete mediators (in this case the pitcrew) and tells the tyrchanger to change the tyres.
 */

 //mediator
#ifndef PITSTOP_H
#define PITSTOP_H

#include "TyreStrategy.h"
#include <vector>

class PitCrew;

using namespace std;

class PitStop {

public:

	/**
		Constructor
	*/
	PitStop();

	/**
		Destructor
	*/
	virtual ~PitStop();

	/**
		@param crewMember
		@brief adds a crew member to the Pitcrew vector
	*/
	int addCrewMember(PitCrew*);

	/**

		@param tyreStrategy
	*/
	TyreStrategy* changeTyre(TyreStrategy*);
	/**

		@param id
	*/
	PitCrew* getCrewMember(int);

	/**

		@brief get pitstop pitcrew
	*/
	vector<PitCrew*> getPitCrew();

	/**

		@brief set pitstop pitcrew
		@param pitstop
	*/
	void setPitStop(PitStop*);
protected:

	/**
		@brief a vector to hold all the pitcrew members and an int to hold their ID's
	*/
	vector <PitCrew*> pitcrew;
	int crewMemberID;
};

#endif
