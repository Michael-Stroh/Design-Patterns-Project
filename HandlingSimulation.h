/**
   @file HandlingSimulation.h
   @class HandlingSimulation
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef HANDLINGSIMULATION_H

#define HANDLINGSIMULATION_H

#include "Simulation.h"
#include "CarComposite.h"

class HandlingSimulation: public Simulation {

	public:
	
		/**
			Constructor
		*/
		HandlingSimulation();

		/**
			Destructor
		*/
		~HandlingSimulation();

		/**
			
			@param
			@param
			@return
		*/
		Simulation* simulate( CarComposite*, Driver* );
};

#endif
