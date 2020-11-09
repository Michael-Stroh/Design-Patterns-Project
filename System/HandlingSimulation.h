/**
   @file HandlingSimulation.h
   @class HandlingSimulation
   @authors Michael Timothy
   @version 1.0.1
   @brief A simulation that improves the handling of a car part.
 */


#ifndef HANDLINGSIMULATION_H

#define HANDLINGSIMULATION_H

#include "Simulation.h"
#include "SpeedSimulation.h"
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
			Clones the input car part, then adjusts it stats according to the values in the variance array while being sure that none exceed the
			corresponding values in the max array. Returns the Better car part (without deleting anything, deletion takes place in the Engineering Department
			that calls this function.
			@param carPart the carPart to be worked on
			@param variance an array of variances that model how much the acceleration, handling and speed can change respectively
			@param max an array of the max values for the acceleration, handling and speed respectively
			@return The better CarPart out of the cloned part and the new part.
		*/
		CarPart* simulate(CarPart*, float [] , float []);

		void simulate(Driver*);

		/**
			@brief Returns the next simulation that a department should run
		*/
		Simulation* getNextState();
};

#endif
