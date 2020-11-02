/**
   @file CircuitIterator.h
   @class CircuitIterator
   @authors Michael
   @version 1.2.0
   @brief ConcreteIterator participant in the Iterator design pattern
   @details helps traverse CompositeRoad in a linear order
 */

#ifndef CircuitITERATOR_H
#define CircuitITERATOR_H

#include "Iterator.h"
#include "CompositeRoad.h"

class CircuitIterator: public Iterator {

	public:
		
		/**
			@brief Constructor
		 	Creates the Object
		*/
		CircuitIterator();

		/**
			@brief Constructor
		 	Creates the Object

		 	@param[out]
		*/
		CircuitIterator( CompositeRoad* );

		/**
			@brief Destructor
		 	Frees the memory
		*/
		~CircuitIterator();

		/**
			Sets the index to the first element
		*/
		void first();

		/**
			Sets the index to the next element
		*/
		void next();
		
		/**
			Determines if index is on the last element
		*/
        bool isDone();

		/**
			Returns the current element
		*/
		Circuit* currentItem();

	private:

		/**
			@brief the current location the iterator will access
		*/
		int index = 0;

		/**
			@brief holds the data the iterator is accessing
		*/
		CompositeRoad* array;
};

#endif
