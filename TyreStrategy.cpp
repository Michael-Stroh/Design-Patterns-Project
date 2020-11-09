/**
   @file TyreStrategy.h
   @class TyreStrategy
   @authors Brent
   @version 1.0.0
   @brief creates and maintains the tyre strategy for each race
*/

#ifndef TYRESTRATEGY_H
#define TYRESTRATEGY_H

#include "Tyre.h"
#include "Soft.h"
#include "Medium.h"
#include "Hard.h"
#include "RaceTrack.h"

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <iostream>

using namespace std;

class TyreStrategy {


public:

	/**
		Constructor
	*/
	TyreStrategy();

	/**
		Constructor
		@param RaceTrack
	*/
	TyreStrategy(RaceTrack*);

	/**
		deconstructor
	*/
	~TyreStrategy();

	/**

		@return the tyre vector
	*/
	vector<Tyre*> getTyres();

	/**
		@brief set the tyres of the tyre strategy
		@param a vector of tyres
	*/
	void setTyres(vector<Tyre*>);


	/**
		@return an int array
	*/
	int* getPitLaps();

	/**
		@brief sets when a car should pit
		@param array of ints
	*/
	void setPitLaps(int* arr);

	/**
		@brief gets the number of pits
		@return int
	*/
	int getNumPits();

	/**
		@brief set the number of pits
		@param int
	*/
	void setNumPits(int arr);

	/**
	@brief for debugging purposes
	*/
	void print();

private:

	/**
		@brief vector of tyres
	*/
	vector<Tyre*> tyres;

	/**
		@brief array of ints, each int simbolizes a pit lap
	*/
	int* pitLaps;

	/**
		@brief the number of pits
	*/
	int numPits;
};

#endif
