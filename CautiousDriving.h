/**
   @file CautiousDriving.h
   @class CautiousDriving
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CAUTIOUSDRIVING_H
#define CAUTIOUSDRIVING_H

#include "Driver.h"

class CautiousDriving: public Driver {

	public:
		
		/**
			Constructor
		*/
		CautiousDriving();

		/**
			Constructor
		 	@param
		*/
		CautiousDriving( string  );

		/**
			Constructor
			@param
			@param
			@param
		*/
		CautiousDriving( string, int, float );

		/**
			Destructor
		*/
		~CautiousDriving();

		/**
			Displays and returns the details of the object
			@return
		*/
		string displayDriver();
};

#endif
