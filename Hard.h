/**
   @file Hard.h
   @class Hard
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef HARD_H
#define HARD_H

#include "Tyre.h"

class Hard: public Tyre {

	public:
		
		/**
			Constructor
		*/
		Hard();

		/**
			Constructor
			@param
			@param
			@param
		*/
		Hard( int, int, float );

		/**
			Desstructor
		*/
		~Hard();

		/**
			
		*/
		void usage();
};

#endif
