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
			@param
			@param
			@param
		*/
		TyreType( int, int, float );

		/**
			Destructor
		*/
		~TyreType();

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
