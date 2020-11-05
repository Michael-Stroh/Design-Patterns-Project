/**
   @file TyreStrategy.h
   @class TyreStrategy
   @authors Michael
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

<<<<<<< HEAD
=======
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <iostream>

using namespace std;

>>>>>>> BrentsBranch
class TyreStrategy {


	public:
		
		/**
			Constructor
		*/
		TyreStrategy();
		TyreStrategy(RaceTrack*  rt);

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
		int* pitLaps;
		int numPits;

};

#endif
