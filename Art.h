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

class Art: public CarPart {

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

		CarPart* clone();

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
		void setBrand(string);

		/**
			Returns the handing score for this carPart
			@return the handling of this part
		*/
		float getHandling();

		/**
			Sets the stored handling to the given value.
			@param newHandling is the value to change handling to.
		*/
		void setHandling(float);

		/**
			Returns the speed score for this part
			@return the speed of this part
		*/
		float getSpeed();

		/**
			Sets the stored handling to the given value
			@param newSpeed is the value to change speed to.
		*/
		void setSpeed(float);

		/**
			Returns the acceleration score for this part
			@return the acceleration of this part
		*/
		float getAcceleration();

		/**
			Sets the stored acceleration to the given value
			@param newAcceleration is the value to change acceleration to.
		*/
		 void setAcceleration(float);

		/**
			Has no obvious use for most derived classes. Will be overridden in derived classes as they need
			@param index
			@param
		*/
		 void add(int, CarPart*);

		/**
			Has no obvious use for most derived classes. Will be overridden in derived classes as they need
			@param index
		*/
		void remove(int);

		/**
			@brief Virtual since CoolingSystem needs to override this function.
		*/
		PartState* createState();
		/**
			@brief Virtual since COolingSystem needs to override this function.
		*/
		void setState(PartState*);

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
