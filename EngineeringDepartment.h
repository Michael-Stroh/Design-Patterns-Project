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
			@param
		*/
		EngineeringDepartment( float );

		/**
			Constructor
			@param
		*/
		EngineeringDepartment( Simulation* );

		/**
			Constructor
			@param
			@param
		*/
		EngineeringDepartment( Simulation*, float );

		/**
			Destructor
		*/
		~EngineeringDepartment();

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
		Simulation* state;
		
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
