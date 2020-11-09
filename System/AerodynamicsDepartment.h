/**
   @file AerodynamicsDepartment.h
   @class AerodynamicsDepartment
   @authors Michael Timothy
   @version 1.0.2
   @brief The Department responsible for making changes and improvements the Body of the car
 */

#ifndef AERODYNAMICSDEPARTMENT_H
#define AERODYNAMICSDEPARTMENT_H

#include "EngineeringDepartment.h"
#include "WindTunnel.h"
#include "Body.h"

class AerodynamicsDepartment: public EngineeringDepartment {

	public:
	
		/**
			Constructor
			@param
		*/
		AerodynamicsDepartment(Budget*, float);


		/**
			Constructor
			@param
			@param
		*/
		AerodynamicsDepartment(Simulation*, Budget*, float);

		/**
			Destructor
		*/
		~AerodynamicsDepartment();

		/**
			Runs the simulation class and returns a pointer to the object
			@return
		*/
		void runSimulation(CarComposite * car);

	private:

		/**
			Constructor
		*/
		AerodynamicsDepartment();

};

#endif
