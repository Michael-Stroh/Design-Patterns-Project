/**
   @file EngineeringCrew.h
   @class EngineeringCrew
   @authors Michael Timothy Kayla
   @version 1.0.1
   @brief A class responsible for building the car as well as upgrading the cars.

 */

#ifndef ENGINEERINGCREW_H
#define ENGINEERINGCREW_H

#include "Car.h"
#include "CarBuilder.h"
#include "EngineeringDepartment.h"
#include "Budget.h"					  //Included by Tim since Engineering Departments need a budget
#include "AerodynamicsDepartment.h"
#include "EngineDepartment.h"
#include "ElectronicsDepartment.h"
#include "ChassisDepartment.h"

class EngineeringCrew {

	public:
	
		/**
			Constructor
		*/
		EngineeringCrew();

		/**
			Destructor
		*/
		~EngineeringCrew();

		/**
			
			@return
		*/
		CarComposite * getCar();

		/**
			
			@param
		*/
		void setCar( CarComposite * );

		/**
			@brief
		*/
		void calculateBudget(int);

		/**
			
			@return
		*/
		CarComposite * getNextSeasonCar();

		/**
			@brief
		*/
		void updateDepartmentBudgets();

		/**
			@param
		*/
		void setNextSeasonCar( CarComposite * );

		/**
			@brief 
		*/
		void prepareForNextRace();
		
	private:
	
		/**
			@brief 
		*/
		CarComposite * car;
		
		/**
			@brief 
		*/
		CarComposite * nextSeasonCar;

		/**
		@brief
		@todo: Provide details on the builder member variable

		*/
		CarBuilder * builder;
		
		/**
			@brief 
		*/
		vector<EngineeringDepartment*> departments;

		/**
			@brief represents the shared budget for the engineering Departments. Might be removed at a later stage
	
		*/
		Budget* budget;

		/**
			@brief specified the amount of money allocated for engineering purposes for each Grand Prix
			@warning this amount still needs to be calibrated
		*/
		const static float moneyPerGrandPrix;
};

#endif
