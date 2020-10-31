/**
   @file TyreStrategy.h
   @class TyreStrategy
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TYRESTRATEGY_H
#define TYRESTRATEGY_H

#include "Tyre.h"

#include <vector>

using namespace std;

class TyreStrategy {


	public:
		
		/**
			Constructor
		*/
		TyreStrategy();

		/**
			Constructor
		*/
		~TyreStrategy();

		/**
			
			@return the stack of tyres
		*/
		vector<Tyre*> getTyres();

		/**

			@param
		*/
		void setTyres( vector<Tyre*> );

	private:
	
		/**
			@brief
		*/
		vector<Tyre*> tyres;

};

#endif
