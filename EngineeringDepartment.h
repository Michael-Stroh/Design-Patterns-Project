/**
   @file EngineeringDepartment.h
   @class EngineeringDepartment
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ENGINEERINGDEPARTMENT_H
#define ENGINEERINGDEPARTMENT_H

#include "Simulation.h"
#include "Budget.h"

class EngineeringDepartment {

	public:
		
		/**
			Constructor
		*/
		EngineeringDepartment();

		/**
			Constructor
			@param budget
		*/
		EngineeringDepartment( float );

		/**
			Constructor
			@param state
		*/
		EngineeringDepartment( Simulation* );

		/**
			Constructor
			@param state
			@param budget
		*/
		EngineeringDepartment( Simulation*, float );

		/**
			Destructor
		*/
		virtual ~EngineeringDepartment();

		/**
			
		*/
		void updateBudget();

		/**
			
			@return
		*/
		virtual Simulation* runSimulation() = 0;
		
	private:
	
		/**
			@brief 
		*/
		Simulation* SimulationState;
		
		/**
			@brief 
		*/
		Budget* remainingBudget;
		
		/**
			@brief 
		*/
		int budgetLimit;
};

#endif
