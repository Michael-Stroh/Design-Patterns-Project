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
#include "Chassis.h"

class ChassisDepartment: public EngineeringDepartment {


	public:
		
		/**
			Default Constructor should not be used.
		*/
		ChassisDepartment();
		
		/**
			Constructor
			@param
		*/
		ChassisDepartment(Budget*, float);

		/**
			Constructor
			@param
			@param
		*/
		ChassisDepartment(Simulation*, Budget*, float);

		/**
			Destructor
		*/
		~ChassisDepartment();


		/**
			Runs a chosen simulation and returns the object
			@return
		*/
		void runSimulation(CarComposite * );
};

#endif
