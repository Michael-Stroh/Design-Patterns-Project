/**
   @file RaceTrack.h
   @class RaceTrack
   @authors Michael
   @version 1.0.0
   @brief 
 */

#ifndef RACETRACK_H
#define RACETRACK_H

#include "Road.h"

class RaceTrack: public Road {

	public:
	
		/**
			Constructor
		*/
		raceTrack();

		/**
			Constructor
			@param
		*/
		RaceTrack( string );

		/**
			Constructor
			@param
			@param
			@param
			@param
			@param
		*/
		RaceTrack( string, float, float, float );

		/**
			Destructor
		*/
		~raceTrack();

		/**
			
		*/
		void print();

		/**
			
		*/
		void timeToFinish();

		/**
			
			@return
		*/
		Iterator* createIterator();

		/**
			
			@return
		*/
		float getDistance();

		/**
			
			@param
		*/
		void setDistance( float );

		/**
			
			@return
		*/
		float getWindForce();

		/**
			
			@return
		*/
		float setWindForce( float );

		/**
			
			@return
		*/
		float getSkill();

		/**
			
			@param
		*/
		void setSkill( float );

	private:
	
		/**
			@brief
		*/
		float distance;
		
		/**
			@brief
		*/
		float windForce;
		
		/**
			@brief
		*/
		float skill;
};

#endif
