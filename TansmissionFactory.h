/**
   @file TansmissionFactory.h
   @class TansmissionFactory
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TANSMISSIONFACTORY_H
#define TANSMISSIONFACTORY_H

#include "CarPartFactory.h"
#include "CarPart.h"

class TansmissionFactory: public CarPartFactory {


	public:
	
		/**
			Constructor
		*/
		TansmissionFactory();

		/**
			Constructor
		*/
		~TansmissionFactory();

		/**
			
			@return
		*/
		CarPart* createPart();
};

#endif
