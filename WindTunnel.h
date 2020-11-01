/**
   @file WindTunnel.h
   @class WindTunnel
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef WINDTUNNEL_H
#define WINDTUNNEL_H

#include "Simulation.h"
#include "CarComposite.h"
#include "Driver.h"
#include "Body.h"

class WindTunnel : Simulation {


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
