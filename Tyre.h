/**
   @file Tyre.h
   @class Tyre
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef Tyre_H
#define Tyre_H

#include <string>
#include <iostream>


using namespace std;

class Tyre {

	public:
	
		/**
			Constructor
		*/
		Tyre();

		/**
			Constructor
			@param StartDurability
			@param StartGrip
			@param StartPressure
		*/
		Tyre( int, int, float );

		/**
			Destructor
		*/
		virtual ~Tyre();

		/**
		
			@return
		*/
		int getDurability();

		/**
			@param
		*/
		void setDurability( int );

		/**
			@return
		*/
		int getGrip();

		/**
			
			@param
		*/
		void setGrip( int );

		/**
			
			@param
		*/
		void setPressure( float );

		/**
			@return
		*/
		float getPressure();
		


		/**
			@return
		*/
		virtual string getType() =0;;
		
		

		/**
				
		*/
		virtual void usage() = 0;
		
	private:
		
		/**
			@brief
		*/
		int durability;
		
		/**
			@brief
		*/
		int grip;
		
		/**
			@brief
		*/
		float pressure;
		
		/** 
			@brief	
		*/
		string type;
};	

#endif
