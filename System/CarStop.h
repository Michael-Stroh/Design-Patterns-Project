/**
   @file CarStop.h
   @class CarStop
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARSTOP_H
#define CARSTOP_H

#include "PitStop.h"
#include "PitCrew.h"
#include "Car.h"

class CarStop: public PitStop {

	public:
		
		/**
			Constructor
		*/
		CarStop();

		/**
			Constructor
		 	@param CarName
		*/
		CarStop( string );

		/**
			Destructor
		*/
		~CarStop();

		/**
			Sets the Car pointer to the parameter and indicates if it was successful
			@return
		*/
		string getName();

		/**
			Sets the Car pointer to the parameter and indicates if it was successful
			@param CarName
			@return
		*/
		void setName( string );

		/**
			Sets the Car pointer to the parameter and indicates if it was successful
			@return
		*/
		Car* getCar();

		/**
			Sets the Car pointer to the parameter and indicates if it was successful
			@param carChange
			@return
		*/
		bool setCar( Car* );

		/**
		Sets the Car pointer to the parameter and indicates if it was successful
		@return
		*/
		PitCrew* getCrew();

		/**
			Sets the Car pointer to the parameter and indicates if it was successful
			@param crewChange
			@return
		*/
		bool setCrew( PitCrew* );

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
