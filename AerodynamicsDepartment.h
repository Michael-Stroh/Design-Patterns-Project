/**
   @file AerodynamicsDepartment.h
   @class AerodynamicsDepartment
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef AERODYNAMICSDEPARTMENT_H
#define AERODYNAMICSDEPARTMENT_H

#include "EngineeringDepartment.h"

class AerodynamicsDepartment: public EngineeringDepartment {

	public:
	
		/**
			Constructor
		*/
		AerodynamicsDepartment();

		/**
			Constructor that takes in a parameter for the budget
			@param budgetLimit
		*/
		AerodynamicsDepartment( float );

		/**
			Constructor that takes in a paramter for the Somulation object
			@param
		*/
		AerodynamicsDepartment( Simulation* );

		/**
			Constructor that takes in a paramter for the Somulation object and budget
			@param
			@param budgetLimit
		*/
		AerodynamicsDepartment( Simulation*, float );

		/**
			Destructor
		*/
		~AerodynamicsDepartment();

		/**
			Runs the simulation class and returns a pointer to the object
			@return
		*/
		Simulation* runSimulation();
};

#endif
