/**
   @file LogisiticsStrategy.h
   @class LogisiticsStrategy
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef LOGISITICSSTRATEGY_H
#define LOGISITICSSTRATEGY_H

#include "logistics.h"

#include <vector> 

class LogisiticsStrategy {

	public:
		
		/**
			Constructor
		*/
		LogisiticsStrategy();

		/**
			Destructor
		*/
		~LogisiticsStrategy();
	
	private:

		/**
			@brief 
		*/
		vector<logistics*> logisitics;
};

#endif
