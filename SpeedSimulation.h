/**
   @file SpeedSimulation.h
   @class SpeedSimulation
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SPEEDSIMULATION_H
#define SPEEDSIMULATION_H

#include "Simulation.h"

class SpeedSimulation: public Simulation {

	public:
	
		/**
			Constructor
		*/
		SpeedSimulation();

		/**
			Constructor
		*/
		~SpeedSimulation();
		
		/**
			Constructor
			@return
		*/
		Simulation* simulate( CarComposite*, Driver* );
};

#endif
