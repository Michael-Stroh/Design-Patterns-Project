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
#include "Car.h"

class CarPart {

	public:
	
		/**
			Constructor
		*/
		CarPart();

		/**
			Constructor
		 	@param CarName
		*/
		CarPart( string );

		/**
			Constructor
			 @param CarName
			 @param BrandName
			 @param
			 @param
			 @param
		*/
		CarPart( string, string, float, float, float );

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
		virtual ~CarPart();

		/**
			Returns a clone/instantiation of the current CarPart object
			@return
		*/
		Car*  clone();

		/**
			Returns the string named Brand
			@return
		*/
		string getName();

		/**
			Sets the Brand string to the parameter given
			@param CarName
		*/
		void setName( string );

		/**
			Returns the string named Brand
			@return
		*/
		string getBrand();

		/**
			Sets the Brand string to the parameter given
			@param BrandName
		*/
		void setBrand( string );

		/**
		Returns the stored handling
		*/
		float getHandling();

		/**
			Sets the stored handling to the given value
			@param handlingValue
		*/
		void setHandling( float );

		/**
			Returns the stored speed
		*/
		float getSpeed();

		/**
			Sets the stored handling to the given value
			@param speedValue
		*/
		void setSpeed( float );

		/**
			Returns the acceleration handling
		*/
		float getAcceleration();

		/**
			Sets the stored handling to the given value
			@param accelerate
		*/
		void setAcceleration( float );

	private:
		
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
		
		/**
     		@brief Stores a pointer to a Tyre object
		*/
		Tyre* tyre;
};

#endif
