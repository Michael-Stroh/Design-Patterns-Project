/**
   @file CautiousDriving.h
   @class CautiousDriving
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CAUTIOUSDRIVING_H
#define CAUTIOUSDRIVING_H

#inlcude "Driver.h"

#include <iostream>
using namespace std;

class CautiousDriving: public Driver {

	public:
		
		/**
			Constructor
		*/
		CautiousDriving();

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
