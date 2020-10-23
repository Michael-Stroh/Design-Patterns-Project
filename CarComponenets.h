/**
   @file CarComponenets.h
   @class CarComponenets
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARCOMPONENETS_H
#define CARCOMPONENETS_H

#include "Container.h"

class CarComponenets: public Container {

	public:
		
		/**
			Constructor
		*/
		CarComponenets();

		/**
			Constructor that takes in a string parameter to describe what  is being stored
		*/
		CarComponenets( string );

		/**
			Destructor
		*/
		~CarComponenets();

		/**
			Returns what is being stored
			@return
		*/
		string getComponents();
};

#endif
