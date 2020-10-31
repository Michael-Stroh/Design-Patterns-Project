#include <iostream>
#include "RaceTrack.h"

RaceTrack::RaceTrack(): Road() {

}

RaceTrack::RaceTrack( string name ): Road( name ) {

}

RaceTrack::RaceTrack( string name, float dist, float wind ):
					Road( name ), distance( dist ), windForce( wind ) {

}

RaceTrack::RaceTrack( string name, RaceTrack::direction dir, float dist, float wind, float strDist,
					  int corners, int RaceLaps ): Road( name ), direct( dir ), distance( dist ), windForce( wind ),
					  laps( RaceLaps ), numCorners( corners ), straightDistance( strDist ) {

}

RaceTrack::~RaceTrack() {

}

void RaceTrack::print() {

	stringstream dist, wind;

	dist << distance;
	wind << windForce;

	Logger::cyan( "Road raced", "The " + getName() + " road was raced " + getDirection() + " with a distance of " + dist.str()
	+  ", a wind force of " + wind.str() + "." );
}

Iterator* RaceTrack::createIterator() {

    return ( new RoadIterator() );
}

float RaceTrack::getDistance() const {

	return distance;
}

void RaceTrack::setDistance( float dist ) {

	distance = dist;
}

float RaceTrack::getWindForce() const {

	return windForce;
}

void RaceTrack::setWindForce( float wind ) {

	windForce = wind;
}

int RaceTrack::getLaps() const {

	return laps;
}

void RaceTrack::setLaps( int RaceLaps ) {

	laps = RaceLaps;
}

int RaceTrack::getCorners() const {

	return numCorners;
}

void RaceTrack::setCorners( int corners ) {

	numCorners = corners;
}

float RaceTrack::getStraightDistance() const {

	return straightDistance;
}

void RaceTrack::setStraightDistance( float dist ) {

	straightDistance = dist;
}

string RaceTrack::getDirection() const {

	switch ( direct  ) {

		case clockwise: 		return "clockwise";
		case anticlockwise: 	return "anti-clockwise";
		default: 				return "Error";
	}
}

void RaceTrack::setDirection( RaceTrack::direction dir ) {

	direct = dir;
}
