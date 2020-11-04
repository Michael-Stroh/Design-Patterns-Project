/**
   @file EngineDepartment.h
   @class EngineDepartment
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ENGINEDEPARTMENT_H
#define ENGINEDEPARTMENT_H

#include "EngineeringDepartment.h"
#include "Engine.h"
#include "AccelerationSimulation.h"

class EngineDepartment: public EngineeringDepartment {

	public:
	
		/**
			Constructor
			@param
		*/
		EngineDepartment( Budget *, float );

	
		/**
			Constructor
			@param
			@param
		*/
		EngineDepartment( Simulation*, Budget *, float );

		/**
			Destructor
		*/
		~EngineDepartment();

		/**
			Runs a simulation by cloning the old part, randomly changing its stats according to the values in the Engine class
			and finally comparing the aggregate of the scores of the new and old part to see which is better. Swaps parts out if better,
			else changes nothing. Deletes the part that is no longer necessary to avoid memory leaks.
			@return The next simulation to run for this department.
		*/
		void runSimulation(CarComposite *);

	private:
		/**
			Constructor
		*/
		EngineDepartment();

};

#endif
