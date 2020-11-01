/**
   @file CircuitIterator.h
   @class CircuitIterator
   @authors Michael
   @version 1.1.0
   @brief 
 */

#ifndef CircuitITERATOR_H
#define CircuitITERATOR_H

#include "Iterator.h"

class CircuitIterator: public Iterator {

	public:
		
		/**
			Constructor
		*/
		CircuitIterator();

		/**
			Constructor
		 	@param[out]
		*/
		CircuitIterator( Circuit* );

		/**
			Destructor
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
