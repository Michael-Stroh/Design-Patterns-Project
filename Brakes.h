/**
   @file Brakes.h
   @class Brakes
   @authors Michael Timothy
   @version 1.0.1
   @brief The brakes of the car. Its priary role will be to provide handling.
   		  The logic behind this is that braking is necessary for taking tight turns.
 */

#ifndef BRAKES_H
#define BRAKES_H

#include "CarPart.h"

class Brakes: public CarPart {

	public:
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Brakes(float, float, float, string);

		/**
			Destructor
		*/
		~Brakes();
	private:
		/**
			Constructor
		*/
		Brakes();

			/**
			@brief Specifies the initial speed value that newly created engines should start with before variance.
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
			@brief Specifies the initial acceleration value that newly created engines should start with before variance.
		*/
		const static float INITAL_ACCELERATION = 0;
		/**
			@brief Specifies by how much the inital acceleration can vary.
		*/
		const static float INITAL_ACCELERATION_VARIANCE = 0;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE = 0;

		/**
			@brief Specifies the initial handling value that newly created engines should start with before variance.
		*/
		const static float INITIAL_HANDLING = 13.0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float INITIAL_HANDLING_VARIABNCE = 2.0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float HANDLING_CHANGE_VARIANCE = 1.0;


};

#endif
