/**
   @file Soft.h
   @class Soft
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SOFT_H
#define SOFT_H

#include "Tyre.h"

#include <string>
#include <iostream>

using namespace std;

class Soft: public Tyre {

	public:

		/**
			Constructor
		*/
		Soft();

		/**
			Constructor
			@param durability
			@param grip
			@param pressure
		*/
		Soft( int, int, float );

		/**
			Destructor
		*/
		~Soft();

		/**
			
		*/
		string getType();
		
		/**
			
		*/
		void usage();
		
		private:
			string type;
};

#endif
