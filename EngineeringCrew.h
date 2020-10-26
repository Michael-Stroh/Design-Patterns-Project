/**
   @file EngineeringCrew.h
   @class EngineeringCrew
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ENGINEERINGCREW_H
#define ENGINEERINGCREW_H

#include "Car.h"
#include "EngineeringDepartment.h"

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
		*/
		vector<EngineeringDepartment*> team;
};

#endif
