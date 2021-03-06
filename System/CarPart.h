/**
   @file CarPart.h
   @class CarPart
   @authors Michael Timothy
   @version 1.0.2
   @brief An interface that each car part must adhere to. CarParts are held
   		in the CarComposite class. 
 */

#ifndef CARPART_H
#define CARPART_H

#include "Car.h"
#include "utilities/Logger.h"
#include <string>
#include "PartState.h"

using namespace std;

/*
	Removed the Tyre * member variable since it makes no sense for 
	all car parts to hold a tyre (eg an engine does not have a tyre in
	real life). 
*/

class CarPart : public Car{

	public:
	
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param n is the name of the part.
			@param b is the brand of the part.
		*/
		CarPart(float, float, float, string, string);
		
		/**
			Constructor for prototype method
			@param part is the CarPart to be copied.
		*/
		CarPart( CarPart& );

		/**
			Destructor
		*/
		virtual ~CarPart();

		/**
			Returns a clone/instantiation of the current CarPart object
			@return a CarPart * 
		*/
		virtual CarPart *  clone();

		/**
			Prints out the specifications of the part. May be overridden by
			derived classes.
		*/
		virtual void print();

		/**
			Returns the string named Brand
			@return a string that is the brand name.
		*/
		virtual string getBrand();

		/**
			Sets the Brand string to the parameter given.
			@param newBrand is the brand to replace the old brand. 
		*/
		virtual void setBrand( string );

		/**
			Returns the handing score for this carPart
			@return the handling of this part
		*/
		virtual float getHandling();

		/**
			Sets the stored handling to the given value.
			@param newHandling is the value to change handling to.
		*/
		virtual void setHandling( float ) ;

		/**
			Returns the speed score for this part
			@return the speed of this part
		*/
		virtual float getSpeed();

		/**
			Sets the stored handling to the given value
			@param newSpeed is the value to change speed to.
		*/
		virtual void setSpeed( float );

		/**
			Returns the acceleration score for this part
			@return the acceleration of this part
		*/
		virtual float getAcceleration();

		/**
			Sets the stored acceleration to the given value
			@param newAcceleration is the value to change acceleration to.
		*/
		virtual void setAcceleration( float );

		/**
			Has no obvious use for most derived classes. Will be overridden in derived classes as they need
			@param index
			@param
		*/
		virtual void add(int, CarPart*);

		/**
			Has no obvious use for most derived classes. Will be overridden in derived classes as they need
			@param index
		*/
		virtual void remove(int);

		/**	
			@brief Virtual since CoolingSystem needs to override this function.
		*/
		virtual PartState* createState();
		/**
			@brief Virtual since COolingSystem needs to override this function.
		*/
		virtual void setState(PartState * );



	
	protected:	//changed from private to protected

		/**
			Default Constructor, made private to restrict access to it and force a different constructor
			to be used.
		*/
		CarPart();

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
     		@brief Stores the acceleration of the car.
		*/
		float acceleration;	
};

#endif
