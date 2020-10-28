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

	output->cyan( "Road raced", "The " + getName() + " road was raced " );
}

void RaceTrack::timeToFinish() {

	// TODO - implement RaceTrack::timeToFinish
	throw "Not yet implemented";
}

Iterator* RaceTrack::createIterator() {

	// TODO - implement RaceTrack::createIterator
	throw "Not yet implemented";
}

float RaceTrack::getDistance() {

	return distance;
}

void RaceTrack::setDistance( float dist ) {

	distance = dist;
}

float RaceTrack::getWindForce() {

	return windForce;
}

float RaceTrack::setWindForce( float wind ) {

	windForce = wind;
}

float RaceTrack::getSkill() {

	return skill;
}

void RaceTrack::setSkill( float RaceSkill ) {

	skill = RaceSkill;
}
