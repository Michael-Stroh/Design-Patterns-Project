/**
   @file TansmissionFactory.h
   @class TansmissionFactory
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TRANSMISSIONFACTORY_H
#define TRANSMISSIONFACTORY_H

#include "CarPartFactory.h"
#include "CarPart.h"

class TransmissionFactory: public CarPartFactory {


	public:
	
		/**
			Constructor
		*/
		TransmissionFactory();

		/**
			Constructor
		*/
		~TransmissionFactory();

		/**
			
			@return
		*/
		CarPart* createPart();
};

#endif
