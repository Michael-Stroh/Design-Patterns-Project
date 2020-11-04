/**
   @file PitStop.h
   @class PitStop
   @authors Michael
   @version 1.0.0
   @brief 
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
		*/
		int addCrewMember(PitCrew *);
		
		/**
			
			@param tyreStrategy
		*/
		TyreStrategy * changeTyre(TyreStrategy *);
		
	protected:

		/**
			@brief 
		*/
		vector <PitCrew*> pitcrew;
		int crewMemberID;
};

#endif
