/**
   @file TyreStrategy.h
   @class TyreStrategy
   @authors Brent
   @version 1.0.0
   @brief 
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
		 	@param rt
		*/
		TyreStrategy( RaceTrack* );

		/**
			Constructor
		*/
		~TyreStrategy();

		/**
			
			@return
		*/
		vector<Tyre*> getTyres();

		/**

			@param
		*/
		void setTyres( vector<Tyre*> );
		
		
		/**
			@param
		*/
		int* getPitLaps();
		
		/**
			@param
		*/
		void setPitLaps(int* arr);
		
		/**
			@param
		*/
		int getNumPits();
		
		/**
			@param
		*/
		void setNumPits(int arr);
		
		/**
			
		*/
		void print();
		
	private:
	
		/**
			@brief
		*/
		vector<Tyre*> tyres;

		/**
			@brief
		*/
		int* pitLaps;

		/**
			@brief
		*/
		int numPits;
};

#endif
