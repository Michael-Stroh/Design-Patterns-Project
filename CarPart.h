/**
   @file CarPart.h
   @class CarPart
   @authors Michael Timothy
   @version 1.0.1
   @brief An interface that each CarPart must adhere to. CarParts are held
   		in the @link CarComposite class.
 */

#ifndef CARPART_H
#define CARPART_H

#include "Car.h"
#include <string>

using namespace std;

/*
	Removed the Tyre * member variable since it makes no sense for 
	all car parts to hold a tyre (eg an engine does not have a tyre in
	real life). Maybe move the get and set brand functions into Car.h?
*/

class CarPart {

	public:
	
		/**
			Default Constructor
		*/
		CarPart();

		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param n is the name of the part
			@param b is the brand of the part
		*/
		CarPart(float, float, float, string, string);
		
		/**
			Constructor for prototype method
			@param part is the CarPart to be copied.
		*/
		CarPart( const Car& );

		/**
			Destructor
		*/
		void ~CarPart();

		/**
			Returns a clone/instantiation of the current CarPart object
			@return a CarPart * (since a CarPart is a Car*).
		*/
		CarPart *  clone();

		/**
			Prints out the specifications of the part. May be overridden by
			derived classes.
		*/
		void print();

		/**
			Returns the string named Brand
			@return a string that is the brand name.
		*/
		string getBrand();

		/**
			Sets the Brand string to the parameter given.
			@param newBrand is the brand to replace the old brand. 
		*/
		void setBrand( string );

		float getHandling();

		/**
			Sets the stored handling to the given value
			@param
		*/
		void setHandling( float ) ;

		/**
			Returns the stored speed
		*/
		float getSpeed();

		/**
			Sets the stored handling to the given value
			@param
		*/
		void setSpeed( float );

		/**
			Returns the acceleration handling
		*/
		float getAcceleration();

		/**
			Sets the stored handling to the given value
			@param
		*/
		void setAcceleration( float );

	protected:	//changed from private to protected
		
		/**
     		@brief stores what type of brand the CarPart
		*/
		string brand;
		
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
	
};

#endif
