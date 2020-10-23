/**
   @file LapResult.h
   @class LapResult
   @authors Michael
   @version 1.0.0
   @brief 
 */


#ifndef LAPRESULT_H
#define LAPRESULT_H

#include "Result.h"

class LapResult: public Result {

	public:
		
		/**
			Constructor
		*/
		LapResult();

		/**
			Constructor
		*/
		LapResult( long );

		/**
			Destructor
		*/
		~LapResult();

		/**
			
			@param
			@return
		*/
		bool addLapTime( Result* );

		/**
			
		*/
		void print();
	
	private:

		/**
			@brief 
		*/
		float lapTime;
		
		/**
			@brief 
		*/
		string teamName;
};

#endif
