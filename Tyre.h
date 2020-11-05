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
#include <vector>
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
		
			@return durability of tyre
		*/
		int getDurability() const;

		/**
			@param durability of tyre
		*/
		void setDurability( int );

		/**
			@return the grip of tyre
		*/
		int getGrip() const;

		/**
			
			@param the grip value
		*/
		void setGrip( int );

		/**
			
			@param
		*/
		void setPressure( float );

		/**
			@return
		*/
		float getPressure() const;

		/**
			calculates the usage of the wheel
			@param the distance of a lap
		*/
		virtual void usage() = 0;

		/**
			sets the type of wheel
		 	@param typeTyre
		*/
		void setType( string );

		/**
			returns the type of wheel
		 	@return
		*/
		string getType();

		/**
			calculates the usage per lap
			@param distance of a lap
		*/
		void usage( int );

	private:
		
		/**
			@brief durability of the tyre
		*/
		int durability;
		
		/**
			@brief the grip fo the tyre
		*/
		int grip;
		
		/**
			@brief the pressure of the tyre
		*/
		float pressure;

		/**
			@brief type of tyre
		*/
		string type;
};

#endif