/**
   @file Logisitics.h
   @class Logisitics
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef LOGISITICS_H
#define LOGISITICS_H

#include "Containter.h"

class Logisitics {

	public:
	
		/**
			Constructor
		*/
		Logisitics();

		/**
			Constructor
			@param boolean to tell if its eurpean or not
		*/
		Logisitics( boolean );

		/**
			Constructor
			@param first container is for garage equipment
			@param second container is for the catering equipment
			@param third container is for the car components
		*/
		Logisitics( Containter*, Containter*, Containter* );

		/**
			Destructor
		*/
		~Logisitics();

		/**
			
			@return was supposed to call the handle function for the state diagram
		*/
		virtual Logistics* handleLogistics() = 0;

	private:

		/**
			@brief garage equiment
		*/
		Container* garage;
		
		/**
			@brief catering equipement
		*/
		Container* catering;
		
		/**
			@brief car component 
		*/
		Container* c;
		
		/**
			@brief european = true, non-european = false
		*/
		boolean european;
};

#endif
