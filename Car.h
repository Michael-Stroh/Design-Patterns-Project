/**
   @file Car.h
   @class Car
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CAR_H
#define CAR_H

#include <iostream>

using namespace std;

class Car {

	public:
	
		/**
			Constructor
		*/
		Car();

		/**
			Copy constructor used for the prototype design pattern
		*/
		Car( Car& );

		/**
			Destructor
		*/
		~Car();

		/**
			Makes and returns a clone of the current Car object
			@return
		*/
		virtual Car* clone() = 0;

		/**
			Prints out details about the Car object
		*/
		virtual void print() = 0;

		/**
			Adds the given car object to the given index
			@param index
			@param
		*/
		virtual void add( int, Car* ) = 0;

		/**
			Removes the car object at the given index
			@param index
		*/
		virtual void remove( int ) = 0;

		/**
			Returns the stored handling
		*/
		virtual float getHandling() = 0;

		/**
			Sets the stored handling to the given value
			@param
		*/
		virtual void setHandling( float ) = 0;

		/**
			Returns the stored speed
		*/
		virtual float getSpeed() = 0;

		/**
			Sets the stored handling to the given value
			@param
		*/
		virtual void setSpeed( float ) = 0;

		/**
			Returns the acceleration handling
		*/
		virtual float getAcceleration() = 0;

		/**
			Sets the stored handling to the given value
			@param
		*/
		virtual void setAcceleration( float ) = 0;
};

#endif
