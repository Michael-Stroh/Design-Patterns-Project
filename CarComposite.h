/**
   @file CarComposite.h
   @class CarComposite
   @authors Michael Timothy
   @version 1.0.1
   @brief The Composite Class of the Composite Design Pattern.
   Holds all of the parts that make up a car and implements the
   functions necessary to change them.
 */

#ifndef CARCOMPOSITE_H
#define CARCOMPOSITE_H

#include "CarMemento.h"
#include "Memento.h"
//#include "Tyre.h"
#include "CarPart.h"	//Contains CarPart.h so no need to include it here.
#include <vector>


/*
	Removed all Tyre related things. Thats Brents problem now 	(͡ ° ͜ʖ ͡ °)
*/

class CarComposite {

	public:
		
		/**
			Constructor
		*/
		CarComposite();

		/**
			Copy constructor for prototype design pattern
			@param c is the car to be copied.
		*/
		CarComposite( const Car& );

		/**
			Destructor
		*/
		~CarComposite();

		/**
			Returns a clone of the current Car object.
			@return a CarComposite * (which is of Type Car).
		*/
		Car * clone();

		/**
			Prints out details about the Car object based on each of the parts
			it holds.
		*/
		void print();

		/**
			Adds the given car object to the given index. Must remove the part
			at the index first to ensure there are no memory leaks.
			@param index is the index to where the part is added.
			@param part is the part to be added at index.
		*/
		void add( int, Car* );

		/**
			Gets the CarPart from the carPart vector at index. Throw
			index out of bounds error. Const since it is used
			in the copy constructor.

			@param index is the index of the part to be fetched.
		*/
		Car * get(int) const;
	
		/**
			Removes the CarPart at the given index. Throws index out of bounds
			error.
			@param index is the index of the part to be removed.
		*/
		void remove( int );

		/**
			Creates a Memento of the current object and returns it
			@return a Memento * for the caretaker to hold.
		*/
		Memento* createCarMemento();

		/**
			Sets the current object to the given Memento
			@param
		*/
		void setCarMemento( CarMemento* );

		//Functions beneath here have not been implemented yet
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
		
	private:
	
		/**
     		@brief A vector of all the car parts that make up the car.
     		Used in conjunction with the enum PartIndices in @link Car .
		*/
		vector<Car*> carParts;
	
		/**
     		@brief The aeroDynamicMultiplier determines how aeroDynamic a car is
     		according to the formula actual_speed=speed_aggregate * aeroDynamicMultiplier.
     		aeroDynamicMultiplier will have a default value of 0.65 and a maximum value
     		of 1.0.
		*/
		float aeroDynamicMultiplier;
		
		/*
     		@brief An array of Tyre pointers.
		*/
		//Tyre** tyres;
		/**
			@brief A constant value that determines the number of tyres a
			car has.
		*/
		const static int NUMTYRES = 4;	

		/**
			@brief A constant value that determines the number of CarParts
			held int the carParts vector.
		*/
		const static int NUMPARTS = 9;
};

#endif
