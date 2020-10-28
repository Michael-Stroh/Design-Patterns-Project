/**
   @file CoolingSystem.h
   @class CoolingSystem
   @authors Michael Timothy
   @version 1.0.1
   @brief The cooling system of the car. It will not provide speed, acceleration or handling to the car
   	      directly, but instead will serve to cool down the engine during a race
 */

#ifndef COOLINGSYSTEM_H
#define COOLINGSYSTEM_H

#include "CarPart.h"

/*
	TODO: Expand on the cooling mechanism. May nneed to have some sort of coupling
	with the Engine class (or CarComposite acts as a mediator).
*/

class CoolingSystem: public CarPart {

	public:
		
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		CoolingSystem(float, float, float, string);

		/**
			@brief Sets the coolingRate to the specified value.
			@param newCoolingRate is the new coolingRate.
		*/
		void setCoolingRate(float);

		/**
			@brief Gets the coolingRate of the cooling system.
			@return the coolingRate of the cooling system.
		*/
		float getCoolingRate(float); 

		/**
			Destructor
		*/
		~CoolingSystem();

	private:
		/**
			Constructor
		*/
		CoolingSystem();

		/**
			@brief The rate at which the cooling system can cool down an engine.
		*/
		float  coolingRate;

		/**
			@brief Specifies the initial coolingRate value that newly created cooling systems should start with before variance.
		*/
		const static float INITAL_COOLINGRATE = 0.9;
		/**
			@brief Specifies by how much the inital coolingRate can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_COOLINGVARIANCE = 0.2;
		/**	
			@brief Specifies by how much the coolingRate may change when acted upon by an
			engineering department. 
		*/
		const static float COOLINGRATE_CHANGE_VARIANCE = 0.1;


		/**
			@brief Specifies the initial speed value that newly created cooling systems should start with before variance.
		*/
		const static float INITAL_SPEED = 0;
		/**
			@brief Specifies by how much the inital speed can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_SPEED_VARIANCE = 0;
		/**	
			@brief Specifies by how much the speed may change when acted upon by an
			engineering department. 
		*/
		const static float SPEED_CHANGE_VARIANCE = 0;

		/**
			@brief Specifies the initial acceleration value that newly created cooling systems should start with before variance.
		*/
		const static float INITAL_ACCELERATION = 0;
		/**
			@brief Specifies by how much the inital acceleration can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITAL_ACCELERATION_VARIANCE = 0;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE = 0;

		/**
			@brief Specifies the initial handling value that newly created cooling systems should start with before variance.
		*/
		const static float INITIAL_HANDLING = 0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float INITIAL_HANDLING_VARIABNCE = 0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float HANDLING_CHANGE_VARIANCE = 0;
};

#endif
