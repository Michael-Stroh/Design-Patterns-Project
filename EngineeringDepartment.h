/**
   @file EngineeringDepartment.h
   @class EngineeringDepartment
   @authors Michael Timothy Kayla
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
			Constructor
			@param budget the budget pointer that specifies the shared budget for each department
			@param budgetLimit a specific Department's budget limit.
		*/
		EngineeringDepartment(Budget *, float );

		/**
			Constructor
			@param state is the initialSimulationState of the EngineeringDepartment
			@param budget budget the budget pointer that specifies the shared budget for each department
			@param budgetLimit budgetLimit a specific Department's budget limit.
		*/
		EngineeringDepartment( Simulation*, Budget * , float );

		/**
			Destructor. Does NOT destroy the budget, that will be handled in the @link EngineeringCrew class.
		*/
		virtual ~EngineeringDepartment();

		/**
			@brief Sets the budget of the department to the specified object
			@param budget is the shared Budget this department makes use of
		*/
		void setBudget(Budget*);

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
			This function is responsible for running a simulation
			@param car is the CarComposite to make improvements to.
		*/
		virtual void runSimulation(CarComposite * ) = 0;

		/**
			@brief Updates
			@param newRemainingBudget is the new balance for the remainingBudget
		*/
		void updateRemainingBudget(float);

		/**
			@brief Updates the remainingBudget of the department after being used.
		*/
		void update();
		
	protected:
	
		/**
			@brief The state of the Department. Is used to determine what aspect of the part is going to be worked on next.
		*/
		Simulation * simulationState;
		
		/**
			@brief The shared Budget object that is responsible for updating the remainingBudget of each EngineeringDepartment
			when it changes during simulations.
		*/
		Budget * budget;
		
		/**
			@brief The remaining budget for EngineeringDepartments
		*/
		float remainingBudget;

		/**
			@brief The specifies the lowest that the budget can reach before departments stop testing. 
			Is set at start of race preparations for each race to allow for a certain amount of work to be done without 
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
