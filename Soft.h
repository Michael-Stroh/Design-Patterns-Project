/**
   @file Soft.h
   @class Soft
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef SOFT_H
#define SOFT_H

class Soft: public TyreType {

	public:

		/**
			Constructor
		*/
		Soft();

		/**
			Constructor
			@param
			@param
			@param
		*/
		Soft( int, int, float );

		/**
			Destructor
		*/
		~Soft();

		/**
			
		*/
		void usage();
};

#endif
