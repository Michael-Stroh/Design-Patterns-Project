/**
   @file TansmissionFactory.h
   @class TansmissionFactory
   @authors Michael Timothy
   @version 1.0.1
   @brief A concrete factory responsible for creating the transmission of a car and ensuring its variables are
   varied and set correctly.
*/

#ifndef TRANSMISSIONFACTORY_H
#define TRANSMISSIONFACTORY_H

#include "CarPartFactory.h"

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
