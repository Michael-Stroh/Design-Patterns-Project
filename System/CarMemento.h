/**
   @file CarMemento.h
   @class CarMemento
   @authors Michael Timothy
   @version 1.0.1
   @brief The class responsible for holding the stored states of each carPart that make up a car.
 */

#ifndef CARMEMENTO_H
#define CARMEMENTO_H

#include "PartState.h"
#include <vector>

using namespace std;

class CarMemento {

	public:
	
		/**
			Constructor
		*/
		CarMemento();

		/**
			@brief Destroys all of the memory allocated for each PartState.
		*/
		~CarMemento();

		/**
			Returns the current stored state
			@return
		*/
		vector<PartState *>  getState();

		/**
			Sets the currently stored state to the given parameter
			@param
			@warning NEED TO BE CAREFUL THERE ARE NO MEMORY LEAKS!!!!
		*/
		void setState(vector<PartState*>);
		
	private:
	
		/**
     		@brief A vector that holds the satte of each part that makes up a car.
		*/
		vector<PartState*> state;
		
};

#endif
