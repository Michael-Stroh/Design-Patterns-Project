#include "RaceTrack.h"

RaceTrack::RaceTrack(): Road() {

}
RaceTrack::RaceTrack( string name ): Road( name ) {

	// TODO - implement RaceTrack::RaceTrack
	throw "Not yet implemented";
}

RaceTrack::RaceTrack( string name, float dist, float wind, float RaceSkill ):
					Road( name ), distance( dist ), windForce( wind ), skill( RaceSkill )  {

	// TODO - implement RaceTrack::RaceTrack
	throw "Not yet implemented";
}

RaceTrack::~RaceTrack() {

}


void RaceTrack::print() {

	// TODO - implement RaceTrack::print
	throw "Not yet implemented";
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

	return this->distance;
}

void RaceTrack::setDistance( float dist ) {

	this->distance = dist;
}

float RaceTrack::getWindForce() {

	return this->windForce;
}

float RaceTrack::setWindForce( float wind ) {

	windForce = wind;
}

float RaceTrack::getSkill() {

	return this->skill;
}

void RaceTrack::setSkill( float RaceSkill ) {

	this->skill = RaceSkill;
}
