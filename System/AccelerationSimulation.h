/**
   @file AccelerationSimulation.h
   @class AccelerationSimulation
   @authors Michael Timothy
   @version 1.0.2
   @brief A Simulation used to improve the acceleration value of a part of the car.
 */

#ifndef ACCELERATIONSIMULATION_H
#define ACCELERATIONSIMULATION_H

#include "Simulation.h"
#include "HandlingSimulation.h"

class AccelerationSimulation: public Simulation {

	public:
	
		/**
			Default Constructor
		*/
		AccelerationSimulation();

		/**
			Destructor
		*/
		~AccelerationSimulation();

		/**
			Clones the input car part, then adjusts it stats according to the values in the variance array while being sure that none exceed the
			corresponding values in the max array. Returns the Better car part (without deleting anything, deletion takes place in the Engineering Department
			that calls this function.
			@param carPart the carPart to be worked on
			@param variance an array of variances that model how much the acceleration, handling and speed can change respectively
			@param max an array of the max values for the acceleration, handling and speed respectively
			@return The better CarPart out of the cloned part and the new part.
		*/
		CarPart* simulate(CarPart*, float variance[], float max[]);

		/**
			@warning This function needs a description
		*/
		void simulate(Driver*);

		/**
			@brief Returns the next simulation that a department should run.
		*/
		Simulation* getNextState();

		
};

#endif
