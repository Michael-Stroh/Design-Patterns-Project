/**
   @file Art.h
   @class Art
   @authors Michael Timothy
   @version 1.0.1
   @brief A Decorator class that models the artwork that makes up the body of the car. 
 */

#ifndef ART_H
#define ART_H

#include "CarPart.h"

class Art {

	public:
	
		/**
			Constructor
		*/
		Art();

		/**
			Constructor
		 	@param
		*/
		Art( string );

		/**
			Destructor
		*/
		virtual ~Art();

		/**
			Prints out the added details to the car
		*/
		void print();

		/**
			@brief Returns the next pointer (either another Art * or the actual Body *) of this object.
		*/
		CarPart * getNext();

		/**
			@brief Appends another art wor to the linked list of artworks
		*/
		void setNext( CarPart * );
	

		/**
			
		*/
		string getDescription();

		/**

		*/
		void setDescription( string );

	

	private:
	
		/**
     		@brief holds a pointer to the next ArtCompnonet stored
		*/
		CarPart * next;
		//ArtComponent* next;

		/**
     		@brief Describes the art
		*/
		string artDescription;
};

#endif
