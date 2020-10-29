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
#include "CarPart.h"	//Contains Car.h so no need to include it here.
#include <vector>


/*
	Removed all Tyre related things. Thats Brents problem now 	(͡ ° ͜ʖ ͡ °)
*/

class CarComposite : public Car{

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
			@param c is the car to be copied.
		*/
		CarComposite( const CarComposite& );

		/**
			Destructor
		*/
		~CarComposite();

		/**
			Returns a clone of the current Car object.
			@return a CarComposite * (which is of Type Car).
		*/
		Car* clone();

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
		CarMemento* createCarMemento();

		/**
			Sets the current object to the given Memento
			@param
		*/
		void setCarMemento( CarMemento* );

		/**
			Returns the sum of the handling scores for each owned carPart.
			@return the logical total handling score of the car.
		*/
		float getHandling();

		/**
			ObseleteFunctin for class CarComposite
			@param newHandling is not used.
		*/
		void setHandling( float );

		/**
			Returns the sum of the speed scores for each owned carPart multiplied by the car's 
			aerodynamics score.
			@return the logical total speed score of the car.
		*/
		float getSpeed();

		/**
			ObseleteFunctin for class CarComposite
			@param newSpeed is not used.
		*/
		void setSpeed( float );

		/**
			Returns the sum of the acceleration scores for each owned carPart.
			@return the logical total acceleration score of the car.
		*/
		 float getAcceleration();

		/**
			ObseleteFunctin for class CarComposite
			@param newAcceleration is not used.
		*/
		void setAcceleration( float );

		/**
			@brief A getter that returns the function at the specified index.
			Should be used in conjucntion with the PartIndices enum.
			@param index The specified index of the car part to fetch.
			@return the car part at the specified index.
		*/
		Car * getPart(int);
		
	private:
	
		/**
     		@brief A vector of all the car parts that make up the car.
     		Used in conjunction with the enum PartIndices in @link Car .
		*/
		vector<Car*> carParts;
	
		/**
			@brief A constant value that determines the number of CarParts
			held int the carParts vector.
		*/
		const static int NUMPARTS;
};

#endif
