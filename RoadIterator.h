/**
   @file RoadIterator.h
   @class RoadIterator
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef ROADITERATOR_H
#define ROADITERATOR_H

#include "Iterator.h"

class RoadIterator: public Iterator {

	public:
		
		/**
			Constructor
		*/
		RoadIterator();

		/**
			Destructor
		*/
		~roadIterator();

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
