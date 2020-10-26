/**
   @file Tyre.h
   @class Tyre
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef Tyre_H
#define Tyre_H

class Tyre {

	public:
	
		/**
			Constructor
		*/
		Tyre();

		/**
			Constructor
			@param
			@param
			@param
		*/
		Tyre( int, int, float );

		/**
			Destructor
		*/
		~Tyre();

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
};

#endif
