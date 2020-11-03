/**
   @file Result.h
   @class Result
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RESULT_H
#define RESULT_H

#include "Result.h"

#include <vector>
#include <string>

using namespace std;

class Result {

	public:
	
		/**
			Constructor
		*/
		Result();

		/**
			Constructor
		*/
		virtual ~Result();

		/**
			
		*/
		virtual void print() = 0;

		/**
			
			@param
		*/
		void addResult( Result* );
		
	private:
	
		/**
			@brief
		*/
		vector<string> racePositions;
};

#endif
