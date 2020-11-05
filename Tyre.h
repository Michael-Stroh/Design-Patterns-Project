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
		
			@return
			@return durability of tyre
		*/
		int getDurability();

		/**
			@param
			@param durability of tyre
		*/
		void setDurability( int );

		/**
			@return
			@return the grip of tyre
		*/
		int getGrip();

		/**
			
			@param
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
			@brief
			@brief durability of the tyre
		*/
		int durability;
		
		/**
			@brief
			@brief the grip fo the tyre
		*/
		int grip;
		
		/**
			@brief
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
