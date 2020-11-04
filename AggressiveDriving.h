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
			Constructor
		 	@param
		*/
		AggressiveDriving( string );

		/**
			Constructor
			@param
			@param
			@param
		*/
		AggressiveDriving( string, int, float );

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
