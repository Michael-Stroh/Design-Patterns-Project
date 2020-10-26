/**
   @file CarComposite.h
   @class CarComposite
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARCOMPOSITE_H
#define CARCOMPOSITE_H

#include "CarMemento.h"
#include "Tyre.h"
#include "Car.h"

#include <vector>

class CarComposite {

	public:
		
		/**
			Constructor
		*/
		CarComposite();

        /**
            Constructor
            @param
        */
        CarComposite( float );

		/**
			Copy constructor for prototype design pattern
		*/
		CarComposite( Car& );

		/**
			Destructor
		*/
		~CarComposite();

		/**
			Returns a clone of the current Car object
			@return
		*/
		Car* clone();

		/**
			Prints out details about the Car object
		*/
		void print();

		/**
			Adds the given car object to the given index
			@param index
			@param
		*/
		void add( int, Car* );
	
		/**
			Removes the car object at the given index
			@param index
		*/
		void remove( int );

		/**
			Creates a Memento of the current object and returns it
			@return
		*/
		CarMemento* createCarMemento();

		/**
			Sets the current object to the given Memento
			@param
		*/
		void setCarMemento( CarMemento* );
		
	private:
	
		/**
     		@brief a Vector of all the Car objects
		*/
		vector<Car*> carParts;
	
		/**
     		@brief how AreoDynamic the Car is
		*/
		float aeroDynamicMultiplier;
		
		/**
     		@brief A pointer to the Tyres the car uses
		*/
		Tyre** tyres;
};

#endif
