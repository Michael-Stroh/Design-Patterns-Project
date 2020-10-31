/**
   @file Engine.h
   @class Engine
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef ENGINE_H
#define ENGINE_H

#include "CarPart.h"

class Engine: public CarPart {

	public:

		/**
			Constructor
		*/
		Engine();

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
			
		*/
		void print();

		/**
			
			@return
		*/
		float determineEffectiveSpeed();

		/**

			@return
		*/
		int getTemp();

		/**

			@param ChangeTemp
		*/
			void setTemp( int );

	private:
		
		/**
			@brief 
		*/
		int temperature;
};

#endif
