/**
   @file RaceTrack.h
   @class RaceTrack
   @authors Michael
   @version 1.3.0
   @brief 
 */

#ifndef RACETRACK_H
#define RACETRACK_H

#include "Road.h"
#include <sstream>

class RaceTrack: public Road {

	public:

		/**
			@brief tracks can be reused and changes how the track is raced
		*/
		enum direction { clockwise = 0, anticlockwise = 1 };

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
		*/
		RaceTrack( string, float, float );

         /**
            Constructor
            @param name
            @param dir
            @param dist
            @param wind
            @param strDist
            @param corners
            @param RaceLaps
        */
         RaceTrack( string, RaceTrack::direction, float, float, float, int, int );

		/**
			Destructor
		*/
		~RaceTrack();

		/**
			
		*/
		void print();

		/**
			
			@return
		*/
		Iterator* createIterator();

		/**
			
			@return
		*/
		float getDistance() const;

		/**
			
			@param dist
		*/
		void setDistance( float );

		/**
			
			@return
		*/
		float getWindForce() const;

		/**
			
			@param wind
		*/
		void setWindForce( float );

		/**

			@return
		*/
		int getLaps() const;

		/**

			@param RaceLaps
		*/
		void setLaps( int );

		/**

			@return
		*/
		int getCorners() const;

		/**

			@param corners
		*/
		void setCorners( int );

		/**

			@return
		*/
		float getStraightDistance() const;

		/**

			@param dist
		*/
		void setStraightDistance( float );

		/**

			@return
		*/
		string getDirection() const;

		/**

			@param dir
		*/
		void setDirection( RaceTrack::direction );

	private:

        /**
             @brief
        */
        int laps = 0;

		/**
			@brief
		*/
		int numCorners = 0;

        /**
			@brief
		*/
		float distance = 0;
		
		/**
			@brief
		*/
		float windForce = 0;

        /**
            @brief
        */
        float straightDistance = 0;

		/**
			@brief
		*/
        direction dirct = clockwise;
};

#endif
