/**
   @file RoadIterator.h
   @class RoadIterator
   @authors Michael
   @version 1.1.0
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
			Constructor
		 	@param[out]
		*/
		RoadIterator( Road* );

		/**
			Destructor
		*/
		~RoadIterator();

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
