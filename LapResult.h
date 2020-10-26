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
		 	@param Time
		*/
		LapResult( float );

		/**
			Constructor
			 @param name
		*/
		LapResult( string );

		/**
				Constructor
				@param name
				@param Time
			*/
		LapResult( string, float );

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

		/**

		*/
		string getTeamName();

		/**

		 	@param name
		*/
		void setTeamName( string );

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
