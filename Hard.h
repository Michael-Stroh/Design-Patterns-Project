/**
   @file Hard.h
   @class Hard
   @authors Michael
   @authors Brenton
   @version 1.0.0
   @brief 
 */


#ifndef HARD_H
#define HARD_H

#include "Tyre.h"

class Hard: public Tyre {

	public:
		
		/**
			Constructor
		*/
		Hard();

		/**
			Constructor
			@param durability
		 	@param grip
		 	@param pressure
		*/
		Hard( int, int, float );

		/**
			Desstructor
		*/
		~Hard();

		/**
			@brief return type of tyre
			@return string type of tyre
		*/
		string getType();

		/**
			@brief to be used after every offical lap
			@param float distance of lap
		*/
		void usage(float);
private:
	string type;
};

#endif
