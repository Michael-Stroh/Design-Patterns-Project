#include "RaceTrack.h"

RaceTrack::RaceTrack(): Road() {

}

RaceTrack::RaceTrack( string name ): Road( name ) {

}

RaceTrack::RaceTrack( string name, float dist, float wind, float RaceSkill ):
					Road( name ), distance( dist ), windForce( wind ), skill( RaceSkill )  {

}

RaceTrack::~RaceTrack() {

}

void RaceTrack::print() {

	Logger::cyan( "Road raced:", "The " + getName() + " road was raced " );
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

float RaceTrack::getSkill() const {

	return skill;
}

void RaceTrack::setSkill( float RaceSkill ) {

	skill = RaceSkill;
}
