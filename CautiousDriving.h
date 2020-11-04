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

#include <string>
#include <iostream>

using namespace std;


class CautiousDriving: public Driver {

	public:
		
		/**
			Constructor
		*/
		CautiousDriving();
		
		/**
			Constructor
		*/
		CautiousDriving(string name, float a);
		
		/**
			Constructor
		*/
		CautiousDriving(Driver* d);

		/**
			Destructor
		*/
		~CautiousDriving();

		/**
			Displays the details of the object
			@return
		*/
		void displayDriver();
};

#endif
