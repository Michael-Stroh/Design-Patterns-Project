/**
   @file Suspension.h
   @class Suspension
   @authors Michael Timothy
   @version 1.0.1
   @brief The suspension of the car. Its primary role will be to provide a balance of speed, handling and acceleration
*/

#ifndef SUSPENSION_H
#define SUSPENSION_H

#include "CarPart.h"

class Suspension: public CarPart {

	public:
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Suspension(float, float, float, string);

		/**
			Destructor
		*/
		~Suspension();

	private:
		/**
			Constructor
		*/
		Suspension();

		/**
			@brief Specifies the initial speed value that newly created suspensions should start with before variance.
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
			@brief Specifies the initial acceleration value that newly created suspensions should start with before variance.
		*/
		const static float INITAL_ACCELERATION = 8;
		/**
			@brief Specifies by how much the inital acceleration can vary where.
		*/
		const static float INITAL_ACCELERATION_VARIANCE = 1;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE = 0.5;

		/**
			@brief Specifies the initial handling value that newly created suspensions should start with before variance.
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
