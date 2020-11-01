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

class CircuitIterator: public Iterator {

	public:
		
		/**
			@brief Constructor
		*/
		CircuitIterator();

		/**
			@brief Constructor
		 	@param[out]
		*/
		CircuitIterator( Circuit* );

		/**
			@brief Destructor
		*/
		~CircuitIterator();

		/**
			
		*/
		void first();

		/**
			
		*/
		void next();
		
		/**
			
		*/
		void isDone();

		/**
			
		*/
		void currentItem();
};

#endif
