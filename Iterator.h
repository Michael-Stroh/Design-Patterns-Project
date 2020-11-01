/**
   @file Iterator.h
   @class Iterator
   @authors Michael
   @version 1.2.0
   @brief Iterator participant in the Iterator design pattern
   @details this is an abstract class, it is mostly used as a template
 */


#ifndef ITERATOR_H
#define ITERATOR_H

class Circuit;

class Iterator {

	public:
	
		/**
			@brief Constructor
		 	Creates the Object
		*/
		Iterator();

		/**
			@brief Constructor
		 	Creates the Object

		 	@param[out]
		*/
		Iterator( Circuit* );

		/**
			@brief Destructor
		 	Frees the memory
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
