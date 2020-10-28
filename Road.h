/**
   @file Road.h
   @class Road
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef ROAD_H
#define ROAD_H

#include <utilities/Logger.h>
#include "Iterator.h"

#include <string>

using namespace std;

Logger* output = new Logger();

class Road {

	public:

		/**
			Constructor
		*/
		Road();

		/**
			Constructor
			@param
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
			
		*/
		virtual void timeToFinish() = 0;

		/**
			
			@return
		*/
		virtual Iterator* createIterator() = 0;


		/**

			@return
		*/
		string getName();

		/**

			@param ChangeName
		*/
		void setName( string );

	private:
	
		/**
			@brief
		*/
		string name;
};

#endif