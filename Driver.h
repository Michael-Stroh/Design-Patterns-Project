/**
   @file Driver.h
   @class Driver
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef DRIVER_H
#define DRIVER_H

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
		 	@param DriverName
		*/
		Driver( string );

		/**
			Constructor
			@param DriverName
			@param DriverAggression
			@param move
		*/
		Driver( string, int, float );

		/**
			Destructor
		*/
		virtual ~Driver();

		/**
			
		*/
		virtual string displayDriver() = 0;

		/**
			
			@return
		*/
		string getName();

		/**
			
			@param DriverName
		*/
		void setName( string );

		/**
			
			@return
		*/
		int getAggression();

		/**
			
			@param DriverAggression
		*/
		void setAggression( int );

		/**
			
			@return
		*/
		float getSpecialMove();

		/**
			
			@param move
		*/
		void setSpecialMove( float );
	
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
