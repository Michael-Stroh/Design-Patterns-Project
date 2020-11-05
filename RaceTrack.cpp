#include "RaceTrack.h"

RaceTrack::RaceTrack(): Circuit() {

}

RaceTrack::RaceTrack( string name ): Circuit( name ) {

}

RaceTrack::RaceTrack( string name, float dist, float wind ): Circuit( name ), distance( dist ), windForce( wind ) {

}

RaceTrack::RaceTrack( string name, RaceTrack::direction dir, float dist, float wind, float strDist,
					 int corners, int RaceLaps ): Circuit( name ), direct( dir ), distance( dist ), windForce( wind ),
												  laps( RaceLaps ), numCorners( corners ), straightDistance( strDist ) {

}

RaceTrack::~RaceTrack() {
}

void RaceTrack::print() {

	//convert the floats to a string
	stringstream dist, wind;

	dist << distance;
	wind << windForce;
	//output the details of the road/track
	Logger::cyan( "Circuit raced", getName() + " circuit was raced " + getDirection() + " with a distance of " + dist.str() + "km and a wind force of " + wind.str() + " units." );
}

Iterator *RaceTrack::createIterator() {

	//create and return an iterator on the current object
	//return ( new CircuitIterator( this ) );
	return nullptr;
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

	//determine which direction the car is going
	switch ( direct ) {

		case clockwise:
			return "clockwise";
		case anticlockwise:
			return "anti-clockwise";
		default:
			return "Error";
	}
}

void RaceTrack::setDirection( RaceTrack::direction dir ) {

	direct = dir;
}

bool RaceTrack::getEuro() const {

	return isEuropean;
}

void RaceTrack::setEuro( bool euro ) {

	isEuropean = euro;
}

float RaceTrack::getAvgPitStops() const {

	return averagePitStop;
}

void RaceTrack::setAvgPitStops( float amount ) {

	averagePitStop = amount;
}

string RaceTrack::getEndDate() const {

	return endingDate;
}

void RaceTrack::setEndDate( string date ) {

	endingDate = date;
}

string RaceTrack::getStartDate() const {

	return startingDate;
}

void RaceTrack::setStartDate( string date ) {

	startingDate = date;
}

