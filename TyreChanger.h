/**
   @file TyreChanger.h
   @class TyreChanger
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TYRECHANGER_H
#define TYRECHANGER_H

#include "PitCrew.h"

class TyreChanger: public PitCrew {

	public:
	
		/**
			Constructor
		*/
		TyreChanger();

		/**
			Destructor
		*/
		~TyreChanger();

		/**
			@param tyre
			@brief change tyres
		*/
		TyreStrategy * replacePart(TyreStrategy *);
		/**
			@brief gets the newTyre
		*/
		TyreStrategy * getNewTyre();
		
	private:
	
		TyreStrategy * newTyre;
};

#endif
