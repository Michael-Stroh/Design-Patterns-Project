/**
   @file Soft.h
   @class Soft
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SOFT_H
#define SOFT_H

#include <iostream>

#include <TyreType.h>

using namespace std;

class Soft: public TyreType {

	public:

		/**
			Constructor
		*/
		Soft();

		/**
			Constructor
			@param durability
			@param grip rating 
			@param pressure
		*/
		Soft( int, int, float );


		/**
			
		*/
		void usage();
};

#endif
