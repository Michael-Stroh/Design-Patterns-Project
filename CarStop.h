/**
   @file CarStop.h
   @class CarStop
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARSTOP_H
#define CARSTOP_H

#include "PitStop.h";
#include "Car.h";
#include "PitCrew.h";

class CarStop: public PitStop {

	public:
		
		/**
			Constructor
		*/
		CarStop();

		/**
			Destructor
		*/
		void ~CarStop();

		/**
			Sets the Car pointer to the parameter and indicates if it was successful
			@param
		*/
		bool setCar( car* );
		
	private:
	
		/**
     		@brief Stores a pointer to a Car object
		*/
		Car* car;
		
		/**
     		@brief Stores a pointer to a PitCrew object
		*/
		PitCrew* crew;
		
		/**
     		@brief Stores the name of the CarStop object
		*/
		string name;
};

#endif
