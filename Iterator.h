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

class Iterator {

	public:
	
		/**
			@brief Constructor
		 	Creates the Object
		*/
		Iterator();

		/**
			@brief Destructor
		 	Frees the memory
		*/
		virtual ~Iterator();

		/**
			,pure virtual
		*/
		virtual void first() = 0;

		/**
			,pure virtual
		*/
		virtual void next() = 0;

		/**
			,pure virtual
		*/
		virtual bool isDone() = 0;
		
		/**
			,pure virtual
		*/
		virtual void currentItem() = 0;
};

#endif
