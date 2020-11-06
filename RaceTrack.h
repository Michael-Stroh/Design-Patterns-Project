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
		enum direction {

			clockwise = 0,
			anticlockwise = 1
		};

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
			@brief Constructor
			@param[in] name used to identify the object
			@param[in] dir: given direction cars will race
			@param[in] dist: given total distance
			@param[in] wind: given amount of wind
			@param[in] strDist: given straight distance of the track
			@param[in] pitStops: given average amount of pit stops
			@param[in] lapTime: given best amount time to keep the track
			@param[in] corners: given amount of corners
			@param[in] RaceLaps: given amount of laps
			@param[in] euro: given basic location of the race
			@param[in] start: given starting date the track will be used
			@param[in] end: given ending date the track will not be used from
		*/
		RaceTrack( string, RaceTrack::direction, float, float, float, float, float, int, int, bool, string, string );

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
		Iterator *createIterator();

		/**
			Returns the stored distance of a single lap
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

		/**
			Returns the basic location of the track
			@return
		*/
		bool getEuro() const;

		/**
			Sets the basic location of the track
			@param[in] euro: determines if the track is European or not
		*/
		void setEuro( bool );

		/**
			Returns the average amounts of pit-stops on the current track
			@return
		*/
		float getAvgPitStops() const;

		/**
			Sets the average amounts of pit-stops on the current track
			@param[in] amount: the average amount given
		*/
		void setAvgPitStops( float );

		/**
			Returns the ending Date that the track will be used
			@return
		*/
		string getEndDate() const;

		/**
			Sets the ending Date that the track will be used
			@param[in] date: the date the track will not be used from
		*/
		void setEndDate( string );

		/**
			Returns the starting Date that the track will be used
			@return
		*/
		string getStartDate() const;

		/**
			Sets the starting Date that the track will be used
			@param[in] date: the date the track will be used from
		*/
		void setStartDate( string );

		/**
			Returns the average amount of time to complete the track
			@return
		*/
		float getBestLapTime() const;

		/**
			Sets the average amount of time to complete the track
			@param[in] time: the time to complete the track in seconds
		*/
		void setBestLapTime( float );

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
			@brief the total distance in Km of a single lap of the track
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
			@brief the average amount of pit-stops on the current track
		*/
		float averagePitStop;

		/**
			@brief the average amount of it takes to complete this track
		*/
		float bestLapTime;

		/**
			@brief the basic location of the track
		*/
		bool isEuropean;

		/**
			@brief the date the track will be used, month then date
		*/
		string endingDate;

		/**
			@brief the date the track will be used, month then date
		*/
		string startingDate;

		/**
			@brief the direction the cars are going to be going on this road/track
		*/
		direction direct = clockwise;


};

#endif