/**
   @file GrandPrix.h
   @class GrandPrix
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef GRAND PRIX_H
#define GRAND PRIX_H

#include "RaceTeam.h"
#include "Result.h"
#include "Circuit.h"
#include "Race.h"

class GrandPrix {

	public:
		
		/**
			Constructor
		*/
		GrandPrix();

		/**
			Destructor
		*/
		~GrandPrix();

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
		Race * race;
};

#endif
