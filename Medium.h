/**
   @file Medium.h
   @class Medium
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef MEDIUM_H
#define MEDIUM_H

#include <iostream>

#include "TyreType.h"

using namespace std;

class Medium: public TyreType {

	public:
		
		/**
			Constructor
		*/
		Medium();

		/**
			Constructor
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
};

#endif
