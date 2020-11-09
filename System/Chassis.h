/**
   @file Chassis.h
   @class Chassis
   @authors Michael Timothy
   @version 1.0.2
   @brief The chassis of the car. Its purpose is to support the body and other components of the car
   		  which is represented through providing handling, speed and acceleration (in smaller amounts than
   		  other dedicated parts such as the engine).
 */

#ifndef CHASSIS_H
#define CHASSIS_H

#include "CarPart.h"

class Chassis: public CarPart {


	public:
	
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Chassis(float, float, float, string);

		/**
			Constructor
		*/
		~Chassis();

		/**
			@brief Specifies the initial speed value that newly created chassis should start with before variance.
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
			@brief Specifies the initial acceleration value that newly created chassis should start with before variance.
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
			@brief Specifies the initial handling value that newly created chassis should start with before variance.
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

		/**
			@brief The maximum value for acceleration for this car part.
		*/
		static const float MAX_ACCELERATION_VALUE;
		/**
			@brief The maximum value for handling for this car part.
		*/
		const static float MAX_HANDLING_VALUE;
		/**
			@brief The maximum value for speed for this car part.
		*/
		const static float MAX_SPEED_VALUE;


	private:
		/**
			Default Constructor
		*/
		Chassis();
};

#endif
