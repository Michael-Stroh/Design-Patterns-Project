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

class logistics {

	public:
	
		/**
			Constructor
		*/
		logistics();

		/**
			Constructor
			@param
		*/
		logistics( bool );

		/**
			Constructor
			@param
			@param
			@param
		*/
		logistics( Container*, Container*, Container* );

		/**
			Destructor
		*/
		~logistics();

		/**
			
			@return
		*/
		virtual logistics* handlelogistics() = 0;

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
