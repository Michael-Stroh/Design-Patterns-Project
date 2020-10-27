/**
   @file Engine.h
   @class Engine
   @authors Michael Timothy
   @version 1.0.1
   @brief The engine of the car. Its primary role will be to provide speed to the car.
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
			@brief Stores the current temperature the engine is at, which
			affects how well it can function and thus, its speed score.
		*/
		int temperature;

		/**
			@brief The intial temperature value that a non-running engine is set to.
		*/
		const static int INITIAL_TEMPERATURE = 0; 

		/**
			Constructor
		*/
		Engine();
};

#endif
