/**
   @file logistics.h
   @class logistics
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef Logistics_H
#define Logistics_H

#include "Container.h"

class Logistics {

	public:
	
		/**
			Constructor
		*/
		Logistics();

		/**
			Constructor
			@param
		*/
		Logistics( bool );

		/**
			Constructor
			@param
			@param
			@param
		*/
		Logistics( Container*, Container*, Container* );

		/**
			Destructor
		*/
		~Logistics();

		/**
			
			@return
		*/
		virtual Logistics* handlelogistics() = 0;

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
		bool isEuropean;
};

#endif
