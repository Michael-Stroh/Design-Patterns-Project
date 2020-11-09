/**
   @file PitStopStrategy.h
   @class PitStopStrategy
   @authors Kayla
   @version 3.0.0
   @brief
 */


#ifndef PITSTOPSTRATEGY_H
#define PITSTOPSTRATEGY_H

#include "PitStop.h"
#include "CarStop.h"
#include "PitCrew.h"
#include "TyreChanger.h"
#include "TyreStrategy.h"



class PitStopStrategy {

public:

	/**
		Constructor
	*/
	PitStopStrategy();

	/**
		Paremeterised Constructor
		@param tyreStrat
	*/
	PitStopStrategy(TyreStrategy*);

	/**
		Destructor
	*/
	~PitStopStrategy();

	/**
		@brief will change tyres when called by pitStopStrategy
	*/

	bool CheckForPitStop(int);

	void CallPitStop();

	/**
		@brief get TyreStrategy
	*/
	TyreStrategy* getTyreStrategy();

	/**
		@param tyreStrat
		@brief set TyreStrategy
	*/
	void setTyreStrategy(TyreStrategy*);

private:

	TyreStrategy* tyre;

};

#endif
