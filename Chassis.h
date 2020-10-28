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
			@param n is the name of the part
			@param b is the brand of the part
		*/
		Chassis(float, float, float, string, string);

		/**
			Constructor
		*/
		~Chassis();

	private:
		/**
			Default Constructor
		*/
		Chassis();

		/**
			@brief Specifies the initial speed value that newly created chassis should start with before variance.
		*/
		const static float INITAL_SPEED = 8;
		/**
			@brief Specifies by how much the inital speed can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_SPEED_VARIANCE = 1;
		/**	
			@brief Specifies by how much the speed may change when acted upon by an
			engineering department. 
		*/
		const static float SPEED_CHANGE_VARIANCE = 0.5;

		/**
			@brief Specifies the initial acceleration value that newly created chassis should start with before variance.
		*/
		const static float INITAL_ACCELERATION = 8;
		/**
			@brief Specifies by how much the inital acceleration can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITAL_ACCELERATION_VARIANCE = 1;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE = 0.5;

		/**
			@brief Specifies the initial handling value that newly created chassis should start with before variance.
		*/
		const static float INITIAL_HANDLING = 8;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float INITIAL_HANDLING_VARIABNCE = 1;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float HANDLING_CHANGE_VARIANCE = 0.5;
};

#endif
