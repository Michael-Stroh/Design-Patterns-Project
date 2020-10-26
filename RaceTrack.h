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
		RaceTrack();

		/**
			Constructor
			@param name
		*/
		RaceTrack( string );

		/**
			Constructor
			@param name
			@param dist
			@param wind
			@param RaceSkill
		*/
		RaceTrack( string, float, float, float );

		/**
			Destructor
		*/
		~RaceTrack();

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
			
			@param dist
		*/
		void setDistance( float );

		/**
			
			@return
		*/
		float getWindForce();

		/**
			
			@return wind
		*/
		float setWindForce( float );

		/**
			
			@return
		*/
		float getSkill();

		/**
			
			@param RaceSkill
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
