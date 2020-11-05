/**
   @file ElectronicsDepartment.h
   @class ElectronicsDepartment
   @authors Michael Timothy
   @version 1.0.2
   @brief The Department responsible for making changes and improvements to the Electronics of a car.
 */


#ifndef ELECTRONICSDEPARTMENT_H
#define ELECTRONICSDEPARTMENT_H

#include "EngineeringDepartment.h"
#include "Electronics.h"

class ElectronicsDepartment : public EngineeringDepartment {

	public:
		
		/**
		Constructor
		@param
	*/
		ElectronicsDepartment(Budget*, float);


		/**
			Constructor
			@param
			@param
		*/
		ElectronicsDepartment(Simulation*, Budget*, float);
	
		/**
			Destructor
		*/
		~ElectronicsDepartment();

		/**
			
			@return
		*/
		void runSimulation(CarComposite * );

	private:
		/**
			Constructor
		*/
		ElectronicsDepartment();

};

#endif
