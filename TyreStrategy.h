/**
   @file TyreStrategy.h
   @class TyreStrategy
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TYRESTRATEGY_H
#define TYRESTRATEGY_H

#include "TyreType.h"

#include <vector>

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
			
			@return
		*/
		vector<TyreType*> getTyres();

	private:
	
		/**
			@brief
		*/
		vector<TyreType*> tyres;

};

#endif
