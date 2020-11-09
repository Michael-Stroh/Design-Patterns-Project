/**
   @file CarTransport.h
   @class CarTransport
   @authors Michael
   @version 1.0.0
   @brief The careTaker for CarMementos.
 */

#ifndef CARTRANSPORT_H
#define CARTRANSPORT_H

class CarTransport {

	public:
		
		/**
			Constructor
		*/
		CarTransport();

		/**
			Destructor
		*/
		~CarTransport();

		/**
			Displays that the car is being moved to the factory
		*/
		void transportCarToFactory();

		/**
			Displays that the car is being moved to the factory
		*/
		void transportCarToRace();
};

#endif
