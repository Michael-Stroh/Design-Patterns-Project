/**
   @file CompositeRoad.h
   @class CompositeRoad
   @authors Michael
   @version 1.5.0
   @brief Composite and ConcreteAggregate participant in the Composite and Iterator design pattern.
   @details holds a group of RaceTrack objects( leaf participant ) and acts like a tree structure.
 */

#ifndef CompositeRoad_H
#define CompositeRoad_H

#include "Circuit.h"
#include <vector>

class CompositeRoad: public Circuit {

	public:

		/**
			@brief Constructor
		 	Creates the object
		*/
		CompositeRoad();

		/**
			@brief Constructor
		 	Creates the object with the given name

		 	@param[in] RoadName used to identify the object
		*/
		CompositeRoad( string );

		/**
			@brief Destructor
		 	Frees all the memory
		*/
		~CompositeRoad();

		/**
			Adds a road object to the tracks vector
			@param[out] CreateRoad: reference to the road we want to add
		*/
		void addRoad( Circuit* );

		/**
			Removes a road object to the tracks vector
			@param[out] RemoveRoad: reference to the road we want to remove
		*/
		void removeRoad( Circuit* );

        /**
            Removes a road object to the tracks vector
            @param[in] RemoveRoad: reference to the help find road we want to remove
        */
        void removeRoad( const string& );

		/**
			Prints  out details, by calling each roads print, about the tracks list
		*/
		void print();

		/**
			Creates an iterator object with the current object so that it can be
		 	traversed in a linear order
			@return the created iterator on the current object
		*/
		Iterator* createIterator();

	private:

		/**
     		@brief a group of RaceTracks so it's easier to store and iterate through
		*/
		vector< Circuit* > tracks;
};

#endif