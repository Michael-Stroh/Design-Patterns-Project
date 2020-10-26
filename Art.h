/**
   @file Art.h
   @class Art
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef ART_H
#define ART_H

#include "Car.h"

class Art: public Car {

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

		*/
		Art* getNext();

		/**

		*/
		void setNext( Art* );

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
		Art* next;
		//ArtComponent* next;

		/**
     		@brief Describes the art
		*/
		string artDescription;
};

#endif
