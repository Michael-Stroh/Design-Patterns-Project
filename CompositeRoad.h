/**
   @file CompositeRoad.h
   @class CompositeRoad
   @authors Michael
   @version 1.3.0
   @brief Composite participant which will hold the roads
 */

#ifndef CompositeRoad_H
#define CompositeRoad_H

#include "Road.h"

#include <vector>

class CompositeRoad: public Road {

	public:
		
		/**
			Constructor
		*/
		CompositeRoad();

		/**
			Constructor
		 	@param RoadName
		*/
		CompositeRoad( string );

		/**
			Destructor
		*/
		~CompositeRoad();

		/**
			Adds a road object to the tracks list
			@param CreateRoad
		*/
		void addRoad( Road* );

		/**
			Removes a road object to the tracks list
			@param RemoveRoad
		*/
		void removeRoad( Road* );

        /**
            Removes a road object to the tracks list
            @param RemoveRoad
        */
        void removeRoad( const string& );

		/**
			Prints out details about the tracks list
		*/
		void print();

		/**

			@return
		*/
		Iterator* createIterator();

	private:
	
		/**
     		@brief Stores a list of tracks so it's easier to store and iterate through
		*/
		vector<Road*> tracks;
};

#endif
