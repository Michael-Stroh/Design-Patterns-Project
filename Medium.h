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

#include <iostream>
#include <string>

using namespace std;

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
			Constructor
		*/
		void usage();
		
		string getType();
		
		private:
			string type;
};

#endif
