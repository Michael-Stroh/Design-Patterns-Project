/**
   @file Acceleration_Simulation.h
   @class Acceleration_Simulation
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef ACCELERATION SIMULATION_H
#define ACCELERATION SIMULATION_H

#include "Simulation.h"

class Acceleration_Simulation: public Simulation {

	public:
	
		/**
			Constructor
		*/
		Acceleration_Simulation();

		/**
			Destructor
		*/
		~Acceleration_Simulation();

		/**
			Runs a simulation on the given Car and Driver and returns the simulation run
			@param
			@param
			@return
		*/
		Simulation* simulate( CarComposite* , Driver* );
};

#endif
