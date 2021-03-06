/**
   @file Body.h
   @class Body
   @authors Michael Timothy
   @version 1.0.1
   @brief The body of the car. Determines the aerodynamics value of the car
   @warning Update the Body should artwork be added here
  
 */

#ifndef BODY_H
#define BODY_H

#include "CarPart.h"

class Body: public CarPart {

	public:
	
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Body(float, float, float, string);


		/**
			Destructor
		*/
		~Body();

		/**
			@brief A copy constructor to be used in conjuction with the custom clone function.
			@param part is the Body to use when initliazing the new Body.
		*/
		Body(Body&);

		/**
			@brief overrides the clone function of the parent class to offer specialized functionality.
			@return the new Cooling SYstem with its coolingrate set correctly
		*/
		CarPart* clone();
		
		/**
			@brief
		*/
		float getAerodynamicMultiplier();

		/**
			@brief
		*/
		void setAerodynamicMultiplier(float);

		/**
			@brief Overrides the corresponding function of the CarPart class to provide specialized functionality.
		*/
		PartState* createState();

		/**
			@brief Overrides the corresponding function of the CarPart class to provide specialized functionality.
		*/
		void setState(PartState* state);

	
		/*
     		@brief Specifies the initial aerodynamicsMultiplier value that newly created bodys should start
     		with before variance.
		*/
		const static float INITIAL_AERODYNAMICS;
		/**
			@brief Specifies by how much the inital aerodynamicMultipler can vary.
		*/
		const static float INITAL_AERODYNAMICS_VARIANCE;
		/**	
			@brief Specifies by how much the aerodynamicsMultiplier may change when acted upon by an
			engineering department. 
		*/
		const static float AERODYNAMICS_VARIANCE;
		/**
			@brief Specifies the maximum amount that the aerodynamicsMultiplier can attain
		*/
		const static float MAX_AERODYNAMICS;

		/**
			@brief Specifies the initial speed value that newly created bodys should start with before variance.
		*/
		const static float INITIAL_SPEED;
		/**
			@brief Specifies by how much the inital speed can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_SPEED_VARIANCE;
		/**	
			@brief Specifies by how much the speed may change when acted upon by an
			engineering department. 
		*/
		const static float SPEED_CHANGE_VARIANCE;

		/**
			@brief Specifies the initial acceleration value that newly created bodys should start with before variance.
		*/
		const static float INITIAL_ACCELERATION;
		/**
			@brief Specifies by how much the inital acceleration can vary.
		*/
		const static float INITIAL_ACCELERATION_VARIANCE;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE;

		/**
			@brief Specifies the initial handling value that newly created bodys should start with before variance.
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
		Body();

		/**
			@brief The aeroDynamicMultiplier determines how aeroDynamic a car is
			according to the formula actual_speed=speed_aggregate * aeroDynamicMultiplier.
			aeroDynamicMultiplier will have a default value of 0.65 and a maximum value
			of 1.0.
		*/
		float aeroDynamicMultiplier;


};

#endif
