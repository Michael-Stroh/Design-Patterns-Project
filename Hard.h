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

#include <iostream>
#include <string>

using namespace std;

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
			calculates the usage per lap
			@param distance of a lap
		*/
		void usage(int);
		
		/**
			returns the type of wheel
		*/
		string getType();
	private:
	/** type of tyre */
		string type;
};

#endif
