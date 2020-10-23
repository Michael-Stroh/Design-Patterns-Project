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

class EngineDepartment: public EngineeringDepartment {

	public:
	
		/**
			Constructor
		*/
		EngineDepartment();

		/**
			Constructor
			@param
		*/
		EngineDepartment( float );

		/**
			Constructor
			@param
		*/
		EngineDepartment( Simulation* );

		/**
			Constructor
			@param
			@param
		*/
		EngineDepartment( Simulation*, float );

		/**
			Destructor
		*/
		~EngineDepartment();

		/**
			
			@return
		*/
		Simulation* runSimulation();
};

#endif
