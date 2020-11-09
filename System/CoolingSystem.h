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
#include "CoolingSystem.h"

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
			@brief A copy constructor to be used in conjuction with the custom clone function.

		*/
		CoolingSystem(CoolingSystem&);

		/**
			@brief overrides the clone function of the parent class to offer specialized functionality.
			@return the new Cooling SYstem with its coolingrate set correctly
		*/
		CarPart* clone();

		/**
			@brief Sets the coolingRate to the specified value.
			@param newCoolingRate is the new coolingRate.
		*/
		void setCoolingRate(float);

		/**
			@brief Gets the coolingRate of the cooling system.
			@return the coolingRate of the cooling system.
		*/
		float getCoolingRate(); 

		/**
			@brief Overrides the corresponding function of the CarPart class to provide specialized functionality.
		*/
		PartState* createState();

		/**
			@brief Overrides the corresponding function of the CarPart class to provide specialized functionality.
		*/
		void setState(PartState* state);

		/**
			Destructor
		*/
		~CoolingSystem();

		/**
			@brief Specifies the initial coolingRate value that newly created cooling systems should start with before variance.
		*/
		const static float INITIAL_COOLINGRATE;
		/**
			@brief Specifies by how much the INITIAL coolingRate can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_COOLINGVARIANCE;
		/**	
			@brief Specifies by how much the coolingRate may change when acted upon by an
			engineering department. 
		*/
		const static float COOLINGRATE_CHANGE_VARIANCE;


		/**
			@brief Specifies the initial speed value that newly created cooling systems should start with before variance.
		*/
		const static float INITIAL_SPEED;
		/**
			@brief Specifies by how much the INITIAL speed can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_SPEED_VARIANCE;
		/**	
			@brief Specifies by how much the speed may change when acted upon by an
			engineering department. 
		*/
		const static float SPEED_CHANGE_VARIANCE;

		/**
			@brief Specifies the initial acceleration value that newly created cooling systems should start with before variance.
		*/
		const static float INITIAL_ACCELERATION;
		/**
			@brief Specifies by how much the INITIAL acceleration can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_ACCELERATION_VARIANCE;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE;

		/**
			@brief Specifies the initial handling value that newly created cooling systems should start with before variance.
		*/
		const static float INITIAL_HANDLING;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float INITIAL_HANDLING_VARIANCE;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float HANDLING_CHANGE_VARIANCE;

	private:
		/**
			Constructor
		*/
		CoolingSystem();
		/**
			@brief The rate at which the cooling system can cool down an engine.
		*/
		float  coolingRate;

};

#endif
