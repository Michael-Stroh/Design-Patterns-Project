/**
   @file WindTunnel.h
   @class WindTunnel
   @authors Michael Timothy
   @version 1.0.1
   @brief  Used to improve the aerodynamics multiplier of the body of a car.
*/

#ifndef WINDTUNNEL_H
#define WINDTUNNEL_H

#include "Simulation.h"
#include "CarComposite.h"
#include "Driver.h"
#include "Body.h"

class WindTunnel : public Simulation {


	public:
	
		/**
			Constructor
		*/
		WindTunnel();

		/**
			Destructor
		*/
		~WindTunnel();

		/**

		 	@return
		*/
		int getUsage();

		/**

			 @param
		*/
		void setUsage( int );

		/**

			 @return
		*/
		int getAllowedUsage();

		/**

			 @param
		*/
		void setAllowedUsage( int );

		/**

			@param
			@param
			@return
		*/
		CarPart* simulate(CarPart*, float[], float[]);

		void simulate(Driver*);

		/**
			@brief Returns the next simulation that a department should run. In this case, this function will probably never be used.
		*/
		Simulation* getNextState();

	private:
	
		/**
			@brief
		*/
		int usage;
		
		/**
			@brief
		*/
		int usageAllowed;	
};

#endif
