/**
   @file Container.h
   @class Container
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>

using namespace std;

class Container {

	public:
	
		/**
			Constructor
		*/
		Container();

		/**
			Constructor
		 	@param
		*/
		Container( string );

		/**
			Destructor
		*/
		virtual ~Container();

		/**

		*/
		string getStored();

		/**

		 	@param
		 	@return
		*/
		void setStored( string );

	protected:

		/**
			@brief
		*/
		string stored;
};

#endif
