/**
   @file Iterator.h
   @class Iterator
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {

	public:
	
		/**
			Constructor
		*/
		iterator();

		/**
			Destructor
		*/
		~iterator();

		/**
			
		*/
		virtual void first() = 0;

		/**
			
		*/
		virtual void next() = 0;

		/**
			
		*/
		virtual void isDone() = 0;
		
		/**
			
		*/
		virtual void currentItem() = 0;
};

#endif
