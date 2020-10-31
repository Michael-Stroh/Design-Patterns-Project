/**
   @file Road.h
   @class Road
   @authors Michael
   @version 1.2.0
   @brief 
 */

#ifndef ROAD_H
#define ROAD_H

#include <utilities/Logger.h>
#include "RoadIterator.h"

class Road {

	public:

		/**
			Constructor
		*/
		Road();

		/**
			Constructor
			@param[in]
		*/
		Road( string );

		/**
			Destructor
		*/
		virtual ~Road();

		/**
			
		*/
		virtual void print() = 0;

		/**
			
			@return
		*/
		virtual Iterator* createIterator() = 0;


		/**

			@return
		*/
		string getName();

		/**

			@param[in] ChangeName
		*/
		void setName( string );

	private:
	
		/**
			@brief
		*/
		string name;
};

#endif