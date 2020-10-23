/**
   @file Simulation.h
   @class Simulation
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include "CarComposite.h"
#include "Driver.h"

class Simulation {

	public:
	
		/**
			Constructor
		*/
		Simulation();

		/**
			Constructor
		*/
		~Simulation();

		/**
			
			@return
		*/
		virtual Simulation* simulate( CarComposite*, Driver* ) = 0;
		
	private:
	
		/**
			@brief
		*/
		Driver* driver;
};

#endif
