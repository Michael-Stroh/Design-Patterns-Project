/**
   @file Circuit.h
   @class Circuit
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Road.h"

class Circuit {

	public:
	
		/**
			Constructor
		*/
		Circuit();
		
		/**
			Constructor that takes a pointer to a Road object and stores it
			@param
		*/
		Circuit( Road* );
		
		/**
			Destructor
		*/
		~Circuit();

	private:
	
		/**
     		@brief Stores a pointer to the roads the cars will race on
		*/
		Road* road;
		
};

#endif
