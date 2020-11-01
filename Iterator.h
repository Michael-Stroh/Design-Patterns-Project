/**
   @file Iterator.h
   @class Iterator
   @authors Michael
   @version 1.1.0
   @brief 
 */


#ifndef ITERATOR_H
#define ITERATOR_H

class Circuit;

class Iterator {

	public:
	
		/**
			Constructor
		*/
		Iterator();

		/**
			Constructor
		 	@param[out]
		*/
		Iterator( Circuit* );

		/**
			Destructor
		*/
		virtual ~Iterator();

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
