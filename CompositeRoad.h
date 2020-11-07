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

#include "CircuitIterator.h"
#include "RaceTrack.h"
#include <vector>

class Circuit;

class CompositeRoad: public Circuit {

	public:

		friend class CircuitIterator;

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
		void addRoad( RaceTrack* );

		/**
			Removes a road object to the tracks vector
			@param[out] RemoveRoad: reference to the road we want to remove
		*/
		void removeRoad( RaceTrack* );

		/**
			Removes a road object to the tracks vector
			@param[in] RemoveRoad: reference to the help find road we want to remove
		*/
		void removeRoad( const string & );

		/**
			Prints  out details, by calling each roads print, about the tracks list
		*/
		void print();

		/**
			Creates an iterator object with the current object so that it can be
			traversed in a linear order
			@return the created iterator on the current object
		*/
		CircuitIterator* createIterator();

		/**
			Determines the size of the tracks vector and returns it
			@return the size of the vector
		*/
		int getSize();

		/**
			Finds the Circuit at a given index
			@param index: location to return from
			@return the specific Circuit in tracks
		*/
		RaceTrack *getRoad( int );

		/**
			@brief Determines the needed Max values from all the stored RaceTracks
		 	this is mostly used to determine the inner works of the car its not so relevant
		*/
		void determineMaxValues();

		/**
			@brief Determines the needed Min values from all the stored RaceTracks
		 	this is mostly used to determine the inner works of the car its not so relevant
		*/
		void determineMinValues();

	private:

		/**
			@brief a group of RaceTracks so it's easier to store and iterate through
		*/
		vector<RaceTrack* > tracks;
};

#include "Circuit.h"

#endif