/**
   @file CompositeRoad.h
   @class CompositeRoad
   @authors Michael
   @version 1.0.0
   @brief Composite Particpant which will hold the roads
 */

#ifndef COMPOSITEROAD_H
#define COMPOSITEROAD_H

#include "Road.h"

class CompositeRoad: public Road {

	public:
		
		/**
			Constructor
		*/
		compositeRoad();

		/**
			Destructor
		*/
		~compositeRoad();

		/**
			Adds a road object to the tracks list
			@param 
		*/
		void addRoad( Road* );

		/**
			Removes a road object to the tracks list
			@param
		*/
		void removeRoad( Road* );

		/**
			Prints out details about the tracks list
		*/
		void print();
	
	private:
	
		/**
     		@brief Stores a list of tracks so it's easier to store and iterate through
		*/
		list<Road*> tracks;
};

#endif
