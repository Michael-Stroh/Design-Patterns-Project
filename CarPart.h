/**
   @file CarPart.h
   @class CarPart
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARPART_H
#define CARPART_H

#include "Tyre.h"

class CarPart {

	public:
	
		/**
			Constructor
		*/
		CarPart();

		/**
			Constructor that takes in and stores a pointer to tyre object
			@param
		*/
		CarPart( Tyre* );
		
		/**
			Constructor for prototype method
			@param
		*/
		CarPart( Car& );

		/**
			Destructor
		*/
		void ~CarPart();

		/**
			Returns a clone/instantiation of the current CarPart object
			@return
		*/
		Car*  clone();

		/**
			Returns the string named Brand
			@return
		*/
		string getBrand();

		/**
			Sets the Brand string to the parameter given
			@param
		*/
		void setBrand( string );
		
	private:
		
		/**
     		@brief stores what type of brand the CarPart
		*/
		string Brand;
		
		/**
     		@brief stores the name of the CarPart
		*/
		string name;
		
		/**
     		@brief Stores how the CarPart handles, this is used to help calculate to help determine the winner
		*/
		float handling;
		
		/**
     		@brief Stores at what speed the CarPart can go
		*/
		float speed;
		
		/**
     		@brief Stores the current speed is
		*/
		float acceleration;
		
		/**
     		@brief Stores a pointer to a Tyre object
		*/
		Tyre* tyre;
};

#endif
