/**
   @file Medium.h
   @class Medium
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef MEDIUM_H
#define MEDIUM_H

#include "Tyre.h"

class Medium: public Tyre {

	public:
		
		/**
			Constructor
		*/
		Medium();

		/**
			Constructor
		 	@param durability
		 	@param grip
		 	@param pressure
		*/
		Medium( int, int, float );

		/**
			Destructor
		*/
		~Medium();

		/**
<<<<<<< HEAD

		*/
		void usage();
=======
			calculates the usage per lap
			@param distance of a lap
		*/
		void usage(int);
};

#endif
