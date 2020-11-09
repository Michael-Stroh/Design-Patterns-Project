/**
   @file CarComposite.h
   @class CarComposite
   @authors Michael Timothy
   @version 1.1.4
   @brief The Composite Class of the Composite Design Pattern.
   Holds all of the parts that make up a car and implements the
   functions necessary to change them.
 */

#ifndef CARCOMPOSITE_H
#define CARCOMPOSITE_H

#include "CarMemento.h"
#include "CarPart.h"	//Contains Car.h so no need to include it here.
#include "Engine.h"		//sometimes we need to access the engine directly
#include "CoolingSystem.h"	//sometimes we need to access the cooling system directly
#include <vector>
#include "PartState.h"
#include "Body.h"


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
		void add( int, CarPart* );

		/**
			Gets the CarPart from the carPart vector at index. Throw
			index out of bounds error. Const since it is used
			in the copy constructor.

			@param index is the index of the part to be fetched.
		*/
		CarPart * getPart(int) const;
	
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
			Sets the current object to the given Memento and deletes the memento that was passed in.
			@param memento is the memento used to set the state of each part of the car.
			
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
			@brief A function that is used to simulate the car running a race. Specifically, it updates the tempreture
			of the engine of the car according to the difficulty of the strategy the Driver is attempting to perform.
			@param[in]: difficulty: represents how difficult the racing is for the car, with 0=easy 1=medium 2=hard.
			The higher the value, the more the engine is heated up. This value will be determined by the RaceTeam class in the

		*/
		void runLap(int);

		/**
			@brief A function used to reset the car after the race by resetting the tempreture of its engine.
		*/
		void resetAfterRace();

		/**
			@brief Returns the amount of fuel in this car.
		*/
		float getFuel();

		/**
			 @brief Sets the fuel of this car to the specified level.
		*/
		void setFuel(float);
		
	private:
	
		/**
			@brief Represents the amount of fuel (in liters) that is inside the car.
		*/
		float fuel;

		/**
     		@brief A vector of all the car parts that make up the car.
     		Used in conjunction with the enum PartIndices in @link Car .
		*/
		vector<CarPart*> carParts;
	
		/**
			@brief A constant value that determines the number of CarParts
			held int the carParts vector.
		*/
		const static int NUMPARTS;
};

#endif
