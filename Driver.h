/**
   @file Driver.h
   @class Driver
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>

using namespace std;

class Driver {

	public:
	
		/**
			Constructor
		*/
		Driver();

		/**
			Constructor
			@param
			@param
			@param
		*/
		Driver( string, int, float );

		/**
			@brief: Value constructor that sets the drivers name for identification purposes during testing
			@todo: Remove from final implementation
		*/
		Driver(string);

		/**
			Destructor
		*/
		virtual ~Driver();

		/**
			
			@return
		*/
		string getName();

		/**
			
			@param
		*/
		void setName( string );

		/**
			
			@return
		*/
		int getAggression();

		/**
			
			@param
		*/
		void setAggression( int );

		/**
			
			@return
		*/
		float getSpecialMove();

		/**
			
			@param
		*/
		void setSpecialMove( float );

		/**
			REMOVED FOR TESTING PURPOSES
			@todo: Uncomment in final implementation
		*/
		// virtual void displayDriver() = 0;
	
	private:
		
		/**
     		@brief 
		*/
		string name;
		
		/**
     		@brief 
		*/
		int aggression;
		
		/**
     		@brief 
		*/
		float specialMove;
};

#endif
