/**
   @file Soft.h
   @class Soft
   @authors Brenton
   @version 1.0.0
   @brief 
 */

#ifndef SOFT_H
#define SOFT_H

#include "Tyre.h"

class Soft: public Tyre {

	public:

		/**
			Constructor
		*/
		Soft();

		/**
			@brief Constructor
			@param durability
			@param grip
			@param pressure
		*/
		Soft( int, int, float );

		/**
			Destructor
		*/
		~Soft();

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
