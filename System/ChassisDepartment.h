/**
   @file ChassisDepartment.h
   @class ChassisDepartment
   @authors Michael Timothy
   @version 1.0.1
   @brief The Engineering Department responsible for improving the chassis of a car.
 */

#ifndef CHASSISDEPARTMENT_H
#define CHASSISDEPARTMENT_H

#include "EngineeringDepartment.h"
#include "Simulation.h"
#include "Chassis.h"

class ChassisDepartment: public EngineeringDepartment {


	public:
		
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
			Runs a chosen simulation and replaces the chassis if it has improved.
		*/
		void runSimulation(CarComposite * );

	private:
		/**
			Default Constructor should not be used.
		*/
		ChassisDepartment();
};

#endif
