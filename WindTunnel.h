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
			
			@param
			@param
			@return
		*/
		Simulation* simulate( CarComposite*, Driver* );

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
