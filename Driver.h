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

using namespace std;

class Driver {

	public:
	
		/**
			Constructor
		*/
		Driver();

		/**
			Constructor
		*/
		Driver( string );

		/**
			Constructor
			@param
			@param
			@param
		*/
		Driver( string, int, float );

		/**
			Destructor
		*/
		~Driver();

		/**
			
		*/
		virtual string displayDriver() = 0;

		/**
			
			@return
		*/
		int getPoints();

		/**
			
			@param
		*/
		void setPoints( int );

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
