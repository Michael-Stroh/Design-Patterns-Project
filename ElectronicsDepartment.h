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
