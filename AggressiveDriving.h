/**
   @file AggressiveDriving.h
   @class AggressiveDriving
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef AGGRESSIVEDRIVING_H
#define AGGRESSIVEDRIVING_H

#include "Driver.h"
#include <string>
#include <iostream>

using namespace std;

class AggressiveDriving: public Driver {

	public:
		
		/**
			Constructor
		*/
		AggressiveDriving();
		
		/**
			Constructor
		*/
		AggressiveDriving(string name, float a);
		
		/**
			Constructor
		*/
		AggressiveDriving(Driver* d);

		/**
			Destructor
		*/
		~AggressiveDriving();

		/**
			Display the detials of the driver
			@return
		*/
		void displayDriver() ;
};

#endif
