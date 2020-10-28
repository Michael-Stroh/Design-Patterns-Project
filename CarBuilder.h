/**
   @file CarBuilder.h
   @class CarBuilder
   @authors Michael Timothy 
   @version 1.0.1
   @brief A Builder class that is responsible for building the initial cars that racing teams will then
   us and upgrade.
 */

#ifndef CARBUILDER_H
#define CARBUILDER_H

#include <vector>

#include "CarComposite.h"
#include "CarPartFactory.h"

#include "EngineFactory.h"
#include "ChassisFactory.h"
#include "TransmissionFactory.h"
#include "SteeringWheelFactory.h"
#include "CoolingSystemFactory.h"
#include "BodyFactory.h"
#include "SuspensionFactory.h"
#include "BrakesFactory.h"
#include "ElectronicsFactory.h"

using namespace std;


class CarBuilder {

	public:
	
		/**
			Constructor
		*/
		CarBuilder();

		/**
			Destructor
		*/
		~CarBuilder();

		/**
			Builds a car object and returns the object created
			@return the newly created car.
		*/
		CarComposite* buildCar();
	
	private:
		
		/**
     		@brief holds a vector of all the factories. Specific factories can be accessed in a similar way
     		to how parts of the CarComposite are accessed using an enum.
		*/
		vector<CarPartFactory*> factories;
};

#endif
