/**
   @file logistics.h
   @class logistics
   @authors Michael
   @authors Brent
   @version 1.0.0
   @brief 
 */

#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "Container.h"

#include <string>
#include <iostream>

using namespace std;

class Logistics {

	public:
		/**
			Constructor
			@param string name of race
			@param bool if european or not
		*/
		Logistics( string, bool );



		/**
			Destructor
		*/
		~Logistics();

		/**
			
			@return
		*/
		
		string getName();

	private:

		/**
			@brief 
		*/
		Container* garage;
		
		/**
			@brief 
		*/
		Container* carComponents;
		
		/**
			@brief 
		*/
		Container* catering;
		
		/**
			@brief 
		*/
		bool isEuropean;
		
		/**
			@brief
		*/
		string name;
};

#endif
