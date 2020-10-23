/**
   @file Grand_Prix.h
   @class Grand_Prix
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef GRAND PRIX_H
#define GRAND PRIX_H

#include "RaceTeam.h"
#include "Result.h"
#include "Circuit.h"

class Grand_Prix {

	public:
		
		/**
			Constructor
		*/
		Grand_Prix();

		/**
			Destructor
		*/
		~Grand_Prix();

		/**
			
			@param
			@return
		*/
		Result* runGrandPrix( RaceTeam* );

		/**
			
		*/
		void displayWinners();
		
	private:
		
		/**
			@brief 
		*/
		Circuit* circuit;
		
		/**
			@brief 
		*/
		Race* race;
};

#endif
