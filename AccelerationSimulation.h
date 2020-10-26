/**
   @file AccelerationSimulation.h
   @class AccelerationSimulation
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef ACCELERATIONSIMULATION_H
#define ACCELERATIONSIMULATION_H

#include "Simulation.h"

class AccelerationSimulation: public Simulation {

	public:
	
		/**
			Constructor
		*/
		AccelerationSimulation();

		/**
			Destructor
		*/
		~AccelerationSimulation();

		/**
			Runs a simulation on the given Car and Driver and returns the simulation run
			@param
			@param
			@return
		*/
		Simulation* simulate( CarComposite* , Driver* );
};

#endif
