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
<<<<<<< HEAD
#include <vector>
#include <iostream>

=======
#include <iostream>


>>>>>>> BrentsBranch
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
		int getDurability();

		/**
			@param durability of tyre
		*/
		void setDurability( int );

		/**
			@return the grip of tyre
		*/
		int getGrip();

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
		float getPressure();
		


		/**
			@return virtual pure method which returns the type of tyre
		*/
		virtual string getType() =0;;
		
		

		/**
			calculates the usage of the wheel
			@param the distance of a lap
		*/
<<<<<<< HEAD
		virtual void usage() = 0;

		/**

		 @param typeTyre
		*/
		void setType( string );

		/**

		 @return
		*/
		string getType();

	protected:
=======
		virtual void usage(int) = 0;
		
	private:
>>>>>>> BrentsBranch
		
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
<<<<<<< HEAD

		/**
			@brief
		*/
		string type;
};
=======
		
	
};	
>>>>>>> BrentsBranch

#endif
