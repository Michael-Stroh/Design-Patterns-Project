/**
   @file Electronics.h
   @class Electronics
   @authors Michael Timothy
   @version 1.0.1 
   @brief The elctronics system of the car. Its primary role will be to provide handling, acceleration
   	      and speed to the car (in the sense that the electronics system coordinates all of the parts of
   	      the car. The better it does this, the more effective )
 */


#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "CarPart.h"

class Electronics: public CarPart {

	public:
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Electronics(float, float, float, string);
		
		/**
			Destructor
		*/
		~Electronics();
	private:
		/**
			Constructor
		*/
		Electronics();

		/**
			@brief Specifies the initial speed value that newly created suspensions should start with before variance.
		*/
		const static float INITAL_SPEED = 8.0;
		/**
			@brief Specifies by how much the inital speed can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_SPEED_VARIANCE = 1.0;
		/**	
			@brief Specifies by how much the speed may change when acted upon by an
			engineering department. 
		*/
		const static float SPEED_CHANGE_VARIANCE = 0.5;

		/**
			@brief Specifies the initial acceleration value that newly created suspensions should start with before variance.
		*/
		const static float INITAL_ACCELERATION = 8.0;
		/**
			@brief Specifies by how much the inital acceleration can vary where.
		*/
		const static float INITAL_ACCELERATION_VARIANCE = 1.0;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE = 0.5;

		/**
			@brief Specifies the initial handling value that newly created suspensions should start with before variance.
		*/
		const static float INITIAL_HANDLING = 8.0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float INITIAL_HANDLING_VARIABNCE = 1.0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float HANDLING_CHANGE_VARIANCE = 0.5;


};

#endif
