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
			@param
		*/
		Logisitics( boolean );

		/**
			Constructor
			@param
			@param
			@param
		*/
		Logisitics( Containter*, Containter*, Containter* );

		/**
			Destructor
		*/
		~Logisitics();

		/**
			
			@return
		*/
		virtual Logistics* handleLogistics() = 0;

	private:

		/**
			@brief 
		*/
		Container* a;
		
		/**
			@brief 
		*/
		Container* b;
		
		/**
			@brief 
		*/
		Container* c;
		
		/**
			@brief 
		*/
		boolean european;
};

#endif
