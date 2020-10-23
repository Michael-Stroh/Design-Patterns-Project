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
	
	private:
		
		/**
			@brief 
		*/
		int temperature;
};

#endif
