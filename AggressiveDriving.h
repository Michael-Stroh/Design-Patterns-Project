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

class AggressiveDriving: public Driver {

	public:
		
		/**
			Constructor
		*/
		AggressiveDriving();

		/**
			Destructor
		*/
		~AggressiveDriving();

		/**
			Display the detials of the driver
			@return
		*/
		string displayDriver();
};

#endif
