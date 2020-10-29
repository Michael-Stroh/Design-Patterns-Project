/**
   @file Engine.h
   @class Engine
   @authors Michael Timothy
   @version 1.0.2
   @brief The engine of the car. Its primary role will be to provide speed and acceleration to the car.
 */


#ifndef ENGINE_H
#define ENGINE_H

#include "CarPart.h"

class Engine: public CarPart {

	public:

	
		/**
			A Constructor that takes in all of the necessary parameters
			to intialize each member variable.
			@param s is the speed.
			@param h is the handling.
			@param a is the acceleration.
			@param b is the brand of the part
		*/
		Engine(float, float, float, string);

		/**
			Constructor
		 	@param StartTemp
		*/
		Engine( int );

		/**
			Destructor
		*/
		~Engine();

		/**	
			@brief Overrides the getSpeed function of the @link CarPart class
			to offer custom functionality.
			@return the current speed this Engine can sustain
		*/
		float getSpeed();

		/**
			@brief Calculates the speed outputted by this engine based on its tempreture
			@return	the effective speed of the engine
		*/
		float determineEffectiveSpeed();

		/**	
			@brief Returns the current temperature of the engine
			@return the temperature
		*/
		float getTemperature();

		/**
			@brief Sets the current temperature of the engine.
			@param newTemperature the new temperature of the engine.
		*/
		void setTemperature(float);

	private:
		
		/**
			@brief Specifies the initial speed value that newly created engines should start with before variance.
		*/
		const static float INITAL_SPEED = 55.0;
		/**
			@brief Specifies by how much the inital speed can vary where speed = initial speed + (variance*n)
			where -1<=n<=1
		*/
		const static float INITIAL_SPEED_VARIANCE = 5.0;
		/**	
			@brief Specifies by how much the speed may change when acted upon by an
			engineering department. 
		*/
		const static float SPEED_CHANGE_VARIANCE = 2.0;

		/**
			@brief Specifies the initial acceleration value that newly created engines should start with before variance.
		*/
		const static float INITAL_ACCELERATION = 55.0;
		/**
			@brief Specifies by how much the inital acceleration can vary.
		*/
		const static float INITAL_ACCELERATION_VARIANCE = 5.0;
		/**	
			@brief Specifies by how much the acceleration may change when acted upon by an
			engineering department. 
		*/
		const static float ACCELERATION_CHANGE_VARIANCE = 2.0;

		/**
			@brief Specifies the initial handling value that newly created engines should start with before variance.
		*/
		const static float INITIAL_HANDLING = 0.0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float INITIAL_HANDLING_VARIABNCE = 0.0;
		/**	
			@brief Specifies by how much the handling may change when acted upon by an
			engineering department. 
		*/
		const static float HANDLING_CHANGE_VARIANCE = 0.0;

		/**
			@brief Stores the current temperature the engine is at, which
			affects how well it can function and thus, its speed score.
		*/
		float temperature;

		/**
			@brief The intial temperature value that a non-running engine is set to.
		*/
		const static float INITIAL_TEMPERATURE = 100.0; 

		/**
			Constructor
		*/
		Engine();
};

#endif
