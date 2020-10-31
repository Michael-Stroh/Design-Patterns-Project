#include "RaceTrack.h"

RaceTrack::RaceTrack(): Road(), distance( 0 ), windForce( 0 ), skill( 0 ) {

}

RaceTrack::RaceTrack( string name ): Road( name ), distance( 0 ), windForce( 0 ), skill( 0 ) {

}

RaceTrack::RaceTrack( string name, float dist, float wind, float RaceSkill ):
					Road( name ), distance( dist ), windForce( wind ), skill( RaceSkill )  {

}

RaceTrack::~RaceTrack() {

}

void RaceTrack::print() {

	stringstream dist, wind, skilled;

	dist << distance;
	wind << windForce;
	skilled << skill;

	Logger::cyan( "Road raced", "The " + getName() + " road was raced with a distance of " + dist.str()
	+  ", a wind force of " + wind.str() + "  and a skill of " + skilled.str() + " needed." );
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
