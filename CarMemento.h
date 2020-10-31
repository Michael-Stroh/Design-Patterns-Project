/**
   @file CarMemento.h
   @class CarMemento
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CARMEMENTO_H
#define CARMEMENTO_H

#include "State.h"

class CarMemento {

	public:
	
		/**
			Constructor
		*/
		CarMemento();

		/**
			Destructor
		*/
		~CarMemento();

		/**
			Returns the current stored state
			@return
		*/
		State * getState();

		/**
			Sets the currently stored state to the given parameter
			@param
		*/
		void setState( State* );
		
	private:
	
		/**
     		@brief Stores a pointer to a state object
		*/
		State* state;
};

#endif
