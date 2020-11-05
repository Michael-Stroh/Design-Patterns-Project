/**
   @file EngineeringCrew.h
   @class EngineeringCrew
   @authors Michael Timothy
   @version 1.0.1
   @brief A class responsible for building the car as well as updating the cars
   @warning update me
 */


#ifndef ENGINEERINGCREW_H
#define ENGINEERINGCREW_H

#include "Car.h"
#include "CarBuilder.h"
#include "EngineeringDepartment.h"
#include "Budget.h"		  //Included by Tim since Engineering Departments need a budget
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
			Constructor
			@param
		*/
		EngineeringCrew( Car* );

		/**
			Destructor
		*/
		~EngineeringCrew();

		/**
			
			@return
		*/
		Car* getCar();

		/**
			
			@param
		*/
		void setCar( Car* );

		/**
			
			@return
		*/
		Car* getNextSeasonCar();

		/**
			
			@param
		*/
		void setNextSeasonCar( Car* );
		
	private:
	
		/**
			@brief 
		*/
		Car* car;
		
		/**
			@brief 
		*/
		Car* nextSeasonCar;

		/**
		@brief
		@todo: Provide details on the builder member variable

		*/
		CarBuilder* builder;
		
		/**
			@brief 
		*/
		vector<EngineeringDepartment*> team;
};

#endif
