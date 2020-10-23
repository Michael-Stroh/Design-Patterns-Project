/**
   @file ChassisDepartment.h
   @class ChassisDepartment
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CHASSISDEPARTMENT_H
#define CHASSISDEPARTMENT_H

#include "EngineeringDepartment.h"
#include "Simulation.h"

class ChassisDepartment: public EngineeringDepartment {


	public:
	
		/**
			Constructor
		*/
		ChassisDepartment();

		/**
			Constructor Constructor that takes a float for the budgetLimit as a parameter and stores it
			@param budget
		*/
		ChassisDepartment( float );

		/**
			Constructor that takes a Simulation pointer as a parameter and stores it
			@param
		*/
		ChassisDepartment( Simulation* );

		/**
			Constructor that takes pointers for the Simulation and budgetLimit and stores them
			@param
			@param budget
		*/
		ChassisDepartment( Simulation*, float );

		/**
			Destructor
		*/
		~ChassisDepartment();

		/**
			Runs a chosen simulation and returns the object
			@return
		*/
		Simulation* runSimulation();
};

#endif
