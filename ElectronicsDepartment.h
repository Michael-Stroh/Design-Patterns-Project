/**
   @file ElectronicsDepartment.h
   @class ElectronicsDepartment
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ELECTRONICSDEPARTMENT_H
#define ELECTRONICSDEPARTMENT_H

#include "EngineeringDepartment.h"

class ElectronicsDepartment: public EngineeringDepartment {

	public:
		
		/**
			Constructor
		*/
		ElectronicsDepartment();

		/**
			Constructor
			@param budget
		*/
		ElectronicsDepartment( float );

		/**
			Constructor
			@param
		*/
		ElectronicsDepartment( Simulation* );

		/**
			Constructor
			@param
			@param
		*/
		ElectronicsDepartment( Simulation*, float );

		/**
			Destructor
		*/
		~ElectronicsDepartment();

		/**
			
			@return
		*/
		Simulation* runSimulation();
};

#endif
