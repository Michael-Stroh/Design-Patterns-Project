/**
   @file TyreType.h
   @class TyreType
   @authors Michael
   @version 1.0.0
   @brief 
*/

#ifndef TYRETYPE_H
#define TYRETYPE_H

class TyreType {

	public:
	
		/**
			Constructor
		*/
		TyreType();

		/**
			Constructor
			@param durability
			@param grip rating
			@param pressure
		*/
		TyreType( int, int, float );

		/**
			Destructor
		*/
		~TyreType();

		/**
		
			@return durability
		*/
		int getDurability();

		/**
			@param durability
		*/
		void setDurability( int );

		/**
			@return grip rating
		*/
		int getGrip();

		/**
			
			@param grip rating
		*/
		void setGrip( int );

		/**
			
			@param pressure value
		*/
		void setPressure( float );

		/**
			@return pressure of the tyre
		*/
		float getPressure();

		/**
				calculates the wear and tear of the tyre, will also "blow-up" tyre if durability is to low
		*/
		virtual void usage() = 0;
		
	private:
		
		/**
			@brief durability of the tyre
		*/
		int durability;
		
		/**
			@brief grip of the tyre, depending on the durability
		*/
		int grip;
		
		/**
			@brief the pressure of the tyre 
		*/
		float pressure;
};

#endif
