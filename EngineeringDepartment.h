/**
   @file EngineeringDepartment.h
   @class EngineeringDepartment
   @authors Michael Timothy
   @version 1.0.1
   @brief An Interface for each of the Concrete Engineering Departments that will improve the parts of the cars to be raced.
 */


#ifndef ENGINEERINGDEPARTMENT_H
#define ENGINEERINGDEPARTMENT_H

#include "Simulation.h"
#include "AccelerationSimulation.h"
#include "Budget.h"
#include<cstdlib>
#include <ctime>

class EngineeringDepartment {

	public:
		
		
		/**
			@param budget the budget pointer that specifies the shared budget for each department
			@param budgetLimit a specific Department's budget limit.
		*/
		EngineeringDepartment(Budget *, float );

		/**
			Constructor
			@param state
			@param budget
			@param budgetLimit
		*/
		EngineeringDepartment( Simulation*, Budget * , float );

		/**
			Destructor. Does NOT destroy the budget, that will be handled in the @link EngineeringCrew class.
		*/
		virtual ~EngineeringDepartment();

		/**
			Sets this objects budget limit to the new specified budgetlimit.
			@param newBudgetLimit is the new limit for this department.
		*/
		void updateBudgetLimit(float);

		/**
			Returns the budgetLimit that has been set for this department.
			@return this department's budgetLimit.
		*/
		float getBudgetLimit();

		/**	
			This function is responsible for 
			@return The next simulation that is the next state of this department.
		*/
		virtual void runSimulation(CarComposite * ) = 0;

		/**
			@brief
		*/
		void updateRemainingBudget(float);
		
	protected:
	
		/**
			@brief The state of the Department. Is used to determine what aspect of the part is going to be worked on next.
		*/
		Simulation * simulationState;
		
		/**
			@brief 
		*/
		Budget * budget;
		
		/**
			@brief The limit that the budget can
		*/
		float remainingBudget;

		/**
			@brief The specifies the lowest that the budget can reach before departments stop testing. 
			Is set at start of race preparations for each race to allow for a certain amount of workk to be done without 
			exhausting the budget too soon.
		*/
		float budgetLimit;

		/**
			@brief The cost to run one simulation.
		*/
		const static float costPerSimulation;

		/**
				Constructor
			*/
		EngineeringDepartment();
		



};

#endif
