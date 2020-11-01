/**
   @file RaceTrack.h
   @class RaceTrack
   @authors Michael
   @version 1.5.0
   @brief leaf participant in the composite design pattern
   @details holds specific details about the road/track
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
		    Creates the object
		*/
		RaceTrack();

		/**
			@brief Constructor
		    Creates the object with the given name

			@param[in] name: used to identify the object
		*/
		RaceTrack( string );

		/**
			@brief Constructor
		    Creates the object with the given name, distance and windForce

			@param[in] name: used to identify the object
			@param[in] dist: given total distance
			@param[in] wind: given amount of wind
		*/
		RaceTrack( string, float, float );

         /**
            @brief Constructor
            @param[in] name used to identify the object
            @param[in] dir: given direction cars will race
            @param[in] dist: given total distance
            @param[in] wind: given amount of wind
            @param[in] strDist: given straight distance of the track
            @param[in] corners: given amount of corners
            @param[in] RaceLaps: given amount of laps
        */
         RaceTrack( string, RaceTrack::direction, float, float, float, int, int );

		/**
			@brief Destructor
		    Frees all the memory
		*/
		~RaceTrack();

		/**
			Prints out details about the current RaceTrack
		*/
		void print();

		/**
            Creates an iterator object with the current object so that it can be
		 	traversed in a linear order
			@return the created iterator on the current object
		*/
		Iterator* createIterator();

		/**
			Returns the stored distance
			@return
		*/
		float getDistance() const;

		/**
			Sets the stored distance
			@param[in] dist: given distance
		*/
		void setDistance( float );

		/**
			Returns the stored wind
			@return
		*/
		float getWindForce() const;

		/**
			Sets the stored wind
			@param[in] wind: given wind
		*/
		void setWindForce( float );

		/**
            Returns the stored amount of laps
			@return
		*/
		int getLaps() const;

		/**
            Sets the stored amount of laps
			@param[in] RaceLaps: given amount of laps
		*/
		void setLaps( int );

		/**
            Returns the stored amount of corners
			@return
		*/
		int getCorners() const;

		/**
            Sets the stored amount of corners
			@param[in] corners: given amount of corners
		*/
		void setCorners( int );

		/**
            Returns the stored straight distance
			@return
		*/
		float getStraightDistance() const;

		/**
            Sets the stored straight distance
			@param[in] dist: given straight distance
		*/
		void setStraightDistance( float );

		/**
            Returns the stored direction
			@return
		*/
		string getDirection() const;

		/**
            Sets the stored direction
			@param[in] dir: given direction
		*/
		void setDirection( RaceTrack::direction );

	private:

        /**
             @brief the amount of laps a car has to make on this road/track
        */
        int laps = 0;

		/**
			@brief  the amount of corner on this road/track
		*/
		int numCorners = 0;

        /**
			@brief the total distance in Km of this road/track
		*/
		float distance = 0;
		
		/**
			@brief the wind this road/track experiences
		    this helps make it more realistic and slows cars down
		*/
		float windForce = 0;

        /**
            @brief the total straight distance of this road/track
        */
        float straightDistance = 0;

		/**
			@brief the direction the cars are going to be going on this road/track
		*/
        direction direct = clockwise;
};

#endif