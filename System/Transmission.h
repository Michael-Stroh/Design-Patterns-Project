/**
   @file Transmission.h
   @class Transmission
   @authors Michael Timothy
   @version 1.0.2
   @brief Represents the transmissin of the car. Its purpose is to transfer the power of the engine into the 
   		  motion of the wheels, thus it will provide speed and acceleration to the car. It provides 10% of the cars speed and acceleration
*/

#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include "CarPart.h"

class Transmission: public CarPart {

	public:

		/**
			Constructor
		*/
		~Transmission();


		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Transmission(float, float, float, string);

		/**
			@brief Specifies the initial speed value that newly created transmissions should start with before variance.
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
			@brief Specifies the initial acceleration value that newly created transmissions should start with before variance.
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
			@brief Specifies the initial handling value that newly created transmission should start with before variance.
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
		Transmission();

};

#endif
