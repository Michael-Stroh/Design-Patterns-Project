/**
   @file RaceTrack.h
   @class RaceTrack
   @authors Michael
   @version 1.5.0
   @brief leaf participant in the composite design pattern
   @details
 */

#ifndef RACETRACK_H
#define RACETRACK_H

#include "Circuit.h"
#include <sstream>

class RaceTrack: public Circuit {

	public:

		/**
			@brief tracks can be reused and changes how the track is raced
		*/
		enum direction { clockwise = 0, anticlockwise = 1 };

		/**
			@brief Constructor
		*/
		RaceTrack();

		/**
			@brief Constructor
			@param[in] name used to identify the object
		*/
		RaceTrack( string );

		/**
			@brief Constructor
			@param[in] name used to identify the object
			@param[in] dist
			@param[in] wind
		*/
		RaceTrack( string, float, float );

         /**
            @brief Constructor
            @param[in] name used to identify the object
            @param[in] dir
            @param[in] dist
            @param[in] wind
            @param[in] strDist
            @param[in] corners
            @param[in] RaceLaps
        */
         RaceTrack( string, RaceTrack::direction, float, float, float, int, int );

		/**
			@brief Destructor
		*/
		~RaceTrack();

		/**
			Prints  out details, by calling each Circuits print, about the tracks list
		*/
		void print();

		/**

			@return the created iterator on the current object
		*/
		Iterator* createIterator();

		/**
			
			@return
		*/
		float getDistance() const;

		/**
			
			@param[in] dist
		*/
		void setDistance( float );

		/**
			
			@return
		*/
		float getWindForce() const;

		/**
			
			@param[in] wind
		*/
		void setWindForce( float );

		/**

			@return
		*/
		int getLaps() const;

		/**

			@param[in] RaceLaps
		*/
		void setLaps( int );

		/**

			@return
		*/
		int getCorners() const;

		/**

			@param[in] corners
		*/
		void setCorners( int );

		/**

			@return
		*/
		float getStraightDistance() const;

		/**

			@param[in] dist
		*/
		void setStraightDistance( float );

		/**

			@return
		*/
		string getDirection() const;

		/**

			@param[in] dir
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
        direction direct = clockwise;
};

#endif