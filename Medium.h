/**
   @file Medium.h
   @class Medium
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef MEDIUM_H
#define MEDIUM_H

#include "Tyre.h"

class Medium: public Tyre {

	public:
		
		/**
			Constructor
		*/
		Medium();

		/**
			Constructor
		 	@param durability
		 	@param grip
		 	@param pressure
		*/
		Medium( int, int, float );

		/**
			Destructor
		*/
		~Medium();

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
