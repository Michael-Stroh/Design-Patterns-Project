/**
   @file Simulation.h
   @class Simulation
   @authors Michael Timothy
   @version 1.0.2
   @brief An interface that all derived Simulations will have to implement. In general, simulations are responsible for improving the parts
   of a car.
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include "CarComposite.h"
#include "Driver.h"

#include <string>

using namespace std;

class Simulation {

	public:
	
		/**
			Constructor
		*/
		Simulation();

		/**
			Constructor
		*/
		virtual ~Simulation();

		/**
			Clones the input car part, then adjusts it stats according to the values in the variance array while being sure that none exceed the
			corresponding values in the max array. Returns the Better car part (without deleting anything, deletion takes place in the Engineering Department
			that calls this function.
			@param the carPart to be worked on
			@param an array of variances that model how much the acceleration, handling and speed can change respectively
			@param an array of the max values for the acceleration, handling and speed respectively
			@return The better CarPart out of the cloned part and the new part.
		*/
		virtual CarPart * simulate( CarPart *, float variance [] , float max[]) = 0;

		/**
			@brief
		*/
		virtual void simulate(Driver*) = 0;

		/**
			@brief Returns the next simulation that a department should run
		*/
		virtual Simulation* getNextState() = 0;

		
	protected:
		/**
			@brief A helper function for Engineering departments that generates a random number
			@return a float between 0.0 and 1.0

		*/
		float generateRandomFraction();
	
		/**
			@brief
		*/
		Driver* driver;
};

#endif
